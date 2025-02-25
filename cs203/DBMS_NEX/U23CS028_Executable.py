import mysql.connector
import sys

def connect_to_database():
    try:
        connection = mysql.connector.connect(
            host="localhost",
            user="root",
            password="root",  # Replace with your MySQL password
            database="MiniProject"
        )
        return connection
    except mysql.connector.Error as err:
        print(f"Error: {err}")
        sys.exit(1)

def fetch_all_procedure_messages(cursor):
    """
    Fetches all messages from a stored procedure execution.
    Returns a list of message dictionaries.
    """
    messages = []
    for result in cursor.stored_results():
        result_messages = result.fetchall()
        column_names = result.column_names  # Fetch column names

        for msg in result_messages:
            # Convert row tuples to dictionaries
            if isinstance(msg, tuple):
                msg_dict = dict(zip(column_names, msg))
                messages.append(msg_dict)
            else:
                messages.append(msg)  # Add dict directly if already one
    while cursor.fetchone():
        pass
    return messages

class JobPortal:
    def __init__(self):
        self.connection = connect_to_database()
        self.cursor = self.connection.cursor(dictionary=True)
        
    def close_connection(self):
        self.cursor.close()
        self.connection.close()

    def commit_changes(self):
        self.connection.commit()

    def rollback_changes(self):
        self.connection.rollback()

    def displayQualificationLvl(self):
        print("Qualification Level Keys")
        print("0. Below Matriculate")
        print("1. Matriculate (10th)")
        print("2. Intermediate (12th) / Diploma")
        print("3. Graduate (Bachelor)")
        print("4. Post-graduate (Master)")
        print("5. Doctorate (PhD)")

    # Seeker Functions
    def add_email(self, seeker_id, email):
        """
        Adds a new email for the seeker using the SeekerEmail stored procedure.
        """
        try:
            self.cursor.callproc('SeekerEmail', (seeker_id, email))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            print(f"Error adding email for seeker_id {seeker_id}: {err}")


    def add_phone(self, seeker_id, phone_number):
        """
        Adds a new phone number for the seeker using the SeekerPhone stored procedure.
        """
        try:
            self.cursor.callproc('SeekerPhone', (seeker_id, phone_number))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            print(f"Error adding phone for seeker_id {seeker_id}: {err}")

    def seeker_login(self, seeker_id, password):
        query = "SELECT * FROM Seeker WHERE SeekerID = %s AND Pass = %s"
        self.cursor.execute(query, (seeker_id, password))
        return self.cursor.fetchone()

    def register_seeker(self, name, qualification, email, phone, password):
        try:
            self.cursor.callproc('SeekerProfile', (name, qualification, email, phone, password))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]

    def view_available_jobs(self):
        query = "SELECT * FROM AvailableJobs"
        self.cursor.execute(query)
        return self.cursor.fetchall()

    def apply_for_job(self, seeker_id, job_id):
        try:
            self.cursor.callproc('apply', (seeker_id, job_id))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]

    def view_applications(self, seeker_id):
        query = """
        SELECT a.*, p.JobTitle, c.CompanyName, i.InterviewDate, i.IOnline, i.Result, i.Feedback
        FROM Application a
        JOIN Posting p ON a.JobID = p.JobID
        JOIN Company c ON p.CompanyID = c.CompanyID
        LEFT JOIN Interview i ON a.ApplicationID = i.ApplicationID
        WHERE a.SeekerID = %s
        """
        self.cursor.execute(query, (seeker_id,))
        return self.cursor.fetchall()

    def add_skill_to_seeker(self, seeker_id, skill_id):
        try:
            self.cursor.callproc('addSkill', (seeker_id, skill_id))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]
    
    def add_new_skill_to_seeker(self, skill_name, description, seeker_id):
        try:
            self.cursor.callproc('newSeekerSkill', (skill_name, description, seeker_id))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]
    
    # Company Functions
    def company_login(self, company_id, password):
        query = "SELECT * FROM Company WHERE CompanyID = %s AND Pass = %s"
        self.cursor.execute(query, (company_id, password))
        return self.cursor.fetchone()

    def register_company(self, name, industry, location, phone, email, password):
        try:
            self.cursor.callproc('CompanyProfile', (name, industry, location, phone, email, password))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]

    def post_job(self, company_id, title, job_type, onsite, description, deadline, salary, min_qual):
        try:
            self.cursor.callproc('newposting', (company_id, title, job_type, onsite, description, 
                                               deadline, salary, min_qual))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]

    def view_company_postings(self, company_id):
        query = """
        SELECT p.*, 
               (SELECT COUNT(*) FROM Application a WHERE a.JobID = p.JobID) as applications_count
        FROM Posting p 
        WHERE p.CompanyID = %s
        ORDER BY p.PostingDate DESC
        """
        self.cursor.execute(query, (company_id,))
        return self.cursor.fetchall()

    def view_applications_for_job(self, job_id):
        query = """
        SELECT a.*, s.SeekerID, s.SeekerName, s.Qualification, i.InterviewDate, i.IOnline, i.Result
        FROM Application a
        JOIN Seeker s ON a.SeekerID = s.SeekerID
        LEFT JOIN Interview i ON a.ApplicationID = i.ApplicationID
        WHERE a.JobID = %s
        """
        self.cursor.execute(query, (job_id,))
        return self.cursor.fetchall()
    
    def schedule_interview(self, date, mode, app_id):
        try:
            self.cursor.callproc('setInterview', (date, mode, app_id))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]

    def update_interview_result(self, interview_id, result, feedback):
        try:
            self.cursor.callproc('setInterviewResult', (interview_id, result, feedback))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]
    
    def add_skill_to_job(self, job_id, skill_id):
        try:
            self.cursor.callproc('reqSkill', (job_id, skill_id))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]
        
    def add_new_skill_to_job(self, skill_name, description, job_id):
        try:
            self.cursor.callproc('newJobSkill', (skill_name, description, job_id))
            messages = fetch_all_procedure_messages(self.cursor)
            self.commit_changes()
            return messages
        except mysql.connector.Error as err:
            self.rollback_changes()
            return [{"ErrorMessage": f"Error: {err}"}]
    
    # view Views
    def showUpcomingInterviews(self,company_id):
        query = """
        SELECT * 
        FROM UpcomingInterview
        WHERE CompanyID = %s
        """
        self.cursor.execute(query,(company_id,))
        messages = fetch_all_procedure_messages(self.cursor)
        return messages
    
    def showInterns(self, company_id):
        query = """
        SELECT *
        FROM Interns
        WHERE CompanyID = %s
        """
        self.cursor.execute(query,(company_id,))
        messages = fetch_all_procedure_messages(self.cursor)
        return messages
    
    def showTopCompanies(self):
        query = "SELECT * FROM TopCompanies"
        self.cursor.execute(query)
        return self.cursor.fetchall()

def main_menu():
    while True:
        print("\n=== Job Portal System ===")
        print("1. Job Seeker Login")
        print("2. Company Login")
        print("3. Register as Job Seeker")
        print("4. Register as Company")
        print("5. Exit")
        
        choice = input("Enter your choice (1-5): ")
        
        if choice == '1':
            seeker_login_menu()
        elif choice == '2':
            company_login_menu()
        elif choice == '3':
            register_seeker_menu()
        elif choice == '4':
            register_company_menu()
        elif choice == '5':
            print("Thank you for using the Job Portal System!")
            sys.exit(0)
        else:
            print("Invalid choice. Please try again.")

def seeker_menu(portal, seeker_id):
    while True:
        print("\n=== Job Seeker Menu ===")
        print("1. Add new email")
        print("2. Add new phone")
        print("3. View Available Jobs")
        print("4. Apply for a Job")
        print("5. View My Applications")
        print("6. Add a Skill to My Profile")
        print("7. Top Companies with offers")
        print("8. Logout")
        
        choice = input("Enter your choice (1-8): ")

        if choice == '1':
            email = input("Enter New Email: ")
            result = portal.add_email(seeker_id, email)
            print_result_message(result)
        
        elif choice == '2':
            phone = input("Enter New Phone Number (10 digits): ")
            result = portal.add_phone(seeker_id, phone)
            print_result_message(result)

        elif choice == '3':
            try:
                jobs = portal.view_available_jobs()
                print("\nAvailable Jobs:")
                for job in jobs:
                    print(f"\nJob ID: {job['JobID']}")
                    print(f"Title: {job['JobTitle']}")
                    print(f"Company: {job['CompanyName']}")
                    print(f"Type: {job['JobType']}")
                    print(f"Salary: ${job['Salary']}")
                    print(f"Deadline: {job['Deadline']}")
            except mysql.connector.Error as err:
                print(f"Error viewing jobs: {err}")
                
        elif choice == '4':
            try:
                job_id = input("Enter Job ID to apply: ")
                result = portal.apply_for_job(seeker_id, job_id)
                print_result_message(result)
            except mysql.connector.Error as err:
                print(f"Error applying for job: {err}")
            
        elif choice == '5':
            try:
                applications = portal.view_applications(seeker_id)
                print("\nYour Applications:")
                for app in applications:
                    print(f"\nApplication ID: {app['ApplicationID']}")
                    print(f"Job: {app['JobTitle']} at {app['CompanyName']}")
                    print(f"Status: {'Accepted' if app['AppStatus'] else 'Rejected'}")
                    if app['InterviewDate']:
                        print(f"Interview Date: {app['InterviewDate']}")
                        print(f"Interview Mode: {'Online' if app['IOnline'] else 'Offline'}")
                        if app['Result'] is not None:
                            print(f"Result: {'Passed' if app['Result'] else 'Failed'}")
                            print(f"Feedback: {app['Feedback']}")
            except mysql.connector.Error as err:
                print(f"Error viewing applications: {err}")

        elif choice == '6':
            # Adding skill to seeker profile
            skill_choice = input("Do you want to add an existing skill (1) or create a new skill (2)? ")
            if skill_choice == '1':
                skill_id = input("Enter Skill ID: ")
                result = portal.add_skill_to_seeker(seeker_id, skill_id)
                print_result_message(result)
            elif skill_choice == '2':
                skill_name = input("Enter Skill Name: ")
                description = input("Enter Skill Description: ")
                result = portal.add_new_skill_to_seeker(skill_name, description, seeker_id)
            else:
                print("Invalid choice")
    
        elif choice == '7':
            try:
                result = portal.showTopCompanies()
                print("\nTop Companies:")
                for i,c in enumerate(result):
                    print(f"\nRank: {i+1}")
                    print(f"CompanyID: {c['CompanyID']}")
                    print(f"Company Name: {c['CompanyName']}")
                    print(f"Total Postings: {c['TotalPostings']}")
            except mysql.connector.Error as err:
                print(f"Error viewing top companies: {err}")

        elif choice == '8':
            break
        else:
            print("Invalid choice. Please try again.")

def company_menu(portal, company_id):
    while True:
        print("\n=== Company Menu ===")
        print("1. Post New Job")
        print("2. View Posted Jobs")
        print("3. View Applications")
        print("4. Schedule Interview")
        print("5. Update Interview Result")
        print("6. Add a Skill to a Job Posting")
        print("7. Show interns")
        print("8. Show upcoming interviews")
        print("9. Logout")
        
        choice = input("Enter your choice (1-9): ")
        
        if choice == '1':
            try:
                print("\nPost New Job:")
                title = input("Job Title: ")
                job_type = input("Job Type (Full time/Part time/Internship): ")
                onsite = input("Onsite (1 for Yes, 0 for No): ") == '1'
                description = input("Job Description: ")
                deadline = input("Deadline (YYYY-MM-DD): ")
                salary = int(input("Salary: "))
                portal.displayQualificationLvl()
                min_qual = int(input("Minimum Qualification (0-5): "))
                
                result = portal.post_job(company_id, title, job_type, onsite, description, 
                                       deadline, salary, min_qual)
                print_result_message(result)
            except mysql.connector.Error as err:
                print(f"Error posting job: {err}")
            
        elif choice == '2':
            try:
                postings = portal.view_company_postings(company_id)
                print("\nYour Job Postings:")
                for post in postings:
                    print(f"\nJob ID: {post['JobID']}")
                    print(f"Title: {post['JobTitle']}")
                    print(f"Type: {post['JobType']}")
                    print(f"Applications: {post['applications_count']}")
                    print(f"Deadline: {post['Deadline']}")
            except mysql.connector.Error as err:
                print(f"Error viewing postings: {err}")
                
        elif choice == '3':
            try:
                job_id = input("Enter Job ID to view applications: ")
                applications = portal.view_applications_for_job(job_id)
                print("\nApplications:")
                for app in applications:
                    print(f"\nApplication ID: {app['ApplicationID']}")
                    print(f"Seeker: {app['SeekerName']}")
                    print(f"Qualification: {app['Qualification']}")
                    print("EmailIDs:")
                    emailq = """
                    SELECT EmailID
                    from EmailIDs
                    where SeekerID = %s
                    """
                    portal.cursor.execute(emailq,(app['SeekerID'],))
                    email = portal.cursor.fetchall()
                    for i,j in enumerate(email):
                        print(f"\t{i+1}. {j['EmailID']}")
                    print("Contact no.s:")
                    phoneq = """
                    SELECT Phone
                    from PhoneContacts
                    where SeekerID = %s
                    """
                    portal.cursor.execute(phoneq,(app['SeekerID'],))
                    phone = portal.cursor.fetchall()
                    for i,j in enumerate(phone):
                        print(f"\t{i+1}. {j['Phone']}")
                    print(f"Application Status: {'Accepted' if app['AppStatus'] else 'Rejected'}")
                    if app['InterviewDate']:
                        print(f"Interview Date: {app['InterviewDate']}")
                        print(f"Interview Mode: {'Online' if app['IOnline'] else 'Offline'}")
                        if app['Result'] is not None:
                            print(f"Result: {'Passed' if app['Result'] else 'Failed'}")
            except mysql.connector.Error as err:
                print(f"Error viewing applications: {err}")
                
        elif choice == '4':
            try:
                app_id = input("Enter Application ID: ")
                date = input("Interview Date (YYYY-MM-DD): ")
                mode = input("Interview Mode (1 for Online, 0 for Offline): ") == '1'
                result = portal.schedule_interview(date, mode, app_id)
                print_result_message(result)
            except mysql.connector.Error as err:
                print(f"Error scheduling interview: {err}")
                
        elif choice == '5':
            try:
                interview_id = input("Enter Interview ID: ")
                result = input("Result (1 for Pass, 0 for Fail): ") == '1'
                feedback = input("Feedback: ")
                result = portal.update_interview_result(interview_id, result, feedback)
                print_result_message(result)
            except mysql.connector.Error as err:
                print(f"Error updating interview result: {err}")
        elif choice == '6':
            # Adding skill to job posting
            job_id = input("Enter Job ID: ")
            skill_choice = input("Do you want to add an existing skill (1) or create a new skill (2)? ")
            if skill_choice == '1':
                skill_id = input("Enter Skill ID: ")
                result = portal.add_skill_to_job(job_id, skill_id)
                print_result_message(result)
            elif skill_choice == '2':
                skill_name = input("Enter Skill Name: ")
                description = input("Enter Skill Description: ")
                result = portal.add_new_skill_to_job(skill_name, description, job_id)
                print_result_message(result)
            else:
                print("Invalid choice")
        elif choice == '7':
            result = portal.showInterns(company_id)
            print_result_message(result)
        elif choice == '8':
            result = portal.showUpcomingInterviews(company_id)
            print_result_message(result)
        elif choice == '9':
            break
        else:
            print("Invalid choice. Please try again.")

def print_result_message(results):
    if not results:
        print("No messages received.")
        
        return
        
    if isinstance(results, list):
        for result in results:
            for key, value in result.items():
                if key != 'ErrorMessage':
                    print(f"Success: {value}")
                else:
                    print(f"Error: {value}")
    else:
        # Handle single message case
        for key, value in results.items():
            if key != 'ErrorMessage':
                print(f"Success: {value}")
            else:
                print(f"Error: {value}")

def seeker_login_menu():
    portal = JobPortal()
    seeker_id = input("Enter Seeker ID: ")
    password = input("Enter Password: ")
    
    user = portal.seeker_login(seeker_id, password)
    if user:
        print(f"\nWelcome, {user['SeekerName']}!")
        seeker_menu(portal, seeker_id)
    else:
        print("Invalid credentials!")
    
    portal.close_connection()

def company_login_menu():
    portal = JobPortal()
    company_id = input("Enter Company ID: ")
    password = input("Enter Password: ")
    
    company = portal.company_login(company_id, password)
    if company:
        print(f"\nWelcome, {company['CompanyName']}!")
        company_menu(portal, company_id)
    else:
        print("Invalid credentials!")
    
    portal.close_connection()

def register_seeker_menu():
    portal = JobPortal()
    print("\nRegister as Job Seeker:")
    name = input("Name: ")
    portal.displayQualificationLvl()
    qualification = int(input("Qualification Level (0-5): "))
    email = input("Email: ")
    phone = input("Phone (10 digits): ")
    password = input("Password: ")
    
    result = portal.register_seeker(name, qualification, email, phone, password)
    print_result_message(result)
    portal.close_connection()

def register_company_menu():
    portal = JobPortal()
    print("\nRegister as Company:")
    name = input("Company Name: ")
    industry = input("Industry: ")
    location = input("Location: ")
    phone = input("Phone (10 digits): ")
    email = input("Email: ")
    password = input("Password: ")
    
    result = portal.register_company(name, industry, location, phone, email, password)
    print_result_message(result)
    portal.close_connection()

if __name__ == "__main__":
    main_menu()