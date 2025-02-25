#include<bits/stdc++.h>
using namespace std;

string Qualified(int); //Function to convert Qualification key to Qualification

class Date{
    int day,month,year;
public:
    Date(){} //Every class has a default constructor of its own, to avoid error on passing as parameter
    Date(int dd, int mm, int yy){
        day = dd;
        month = mm;
        year = yy;
    }
    friend ostream& operator<< (ostream& out, Date D){ // cout<<Date; will simply print the Date in "dd-mm-yyyy" format
        out<<D.day<<'-'<<D.month<<'-'<<D.year;
        return out;
    }
    bool operator< (Date D){ // comparison operators to compare 2 dates, to check for deadlines etc.
        if (year != D.year) return year < D.year;
        else{
            if (month != D.month) return month < D.month;
            else return day < D.day;
        }
    }
    bool operator<= (Date D){
        if (year != D.year) return year < D.year;
        else{
            if (month != D.month) return month < D.month;
            else return day <= D.day;
        }
    }
    // operators below remain unused
    bool operator> (Date D){
        if (year != D.year) return year > D.year;
        else{
            if (month != D.month) return month > D.month;
            else return day > D.day;
        }
    }
    bool operator>= (Date D){
        if (year != D.year) return year > D.year;
        else{
            if (month != D.month) return month > D.month;
            else return day >= D.day;
        }
    }
    bool operator== (Date D){
        return day==D.day && month==D.month && year==D.year;
    }
};

class Application;
class Seeker{
    int Qualification = 0;
    string Name, Email, Phone;
    vector<string> SkillSet;
    vector<Application*> Applied;
public:
    Seeker(){}
    Seeker(string name, string email, string phone, int qualified){
        Name = name;
        Email = email;
        Phone = phone;
        Qualification = qualified;
    }
    void displaySkills(){ //displays Seeker skills
        for(int i=0; i<SkillSet.size(); i++){
            cout<<i+1<<". "<<SkillSet[i]<<endl;
        }
    }
    void Details(){ //Displaying details about Seeker
        cout<<"Name: "<<Name<<endl;
        cout<<"Email: "<<Email<<endl;
        cout<<"Phone: "<<Phone<<endl;
        cout<<"Qualification: "<<Qualified(Qualification)<<endl;
        cout<<"SkillSet:"<<endl;
        displaySkills(); //nesting
        cout<<"---------"<<endl;
    }
    int squal(){ //member function to read private member Qualification
        return Qualification;
    }
    void newSkill(string skill){ //add new skill
        SkillSet.push_back(skill);
    }
    void newapply(Application* apply){ //add new application
        Applied.push_back(apply);
    }
};

class Job{
protected:
    int Salary, MinQual;
    bool Type;
    string Title;
    Date Pdate, deadline;
    vector<string> JobReq;
    vector<Application*> Applied;
public:
    Job(){}
    Job(string post, Date PDate, Date DDate, int sal, int minqual){
        Title = post;
        Pdate = PDate;
        deadline = DDate;
        Salary = sal;
        MinQual = minqual;
    }
    void displaySkills(){ // display job pre-requisites
        for(int i=0; i<JobReq.size(); i++){
            cout<<i+1<<". "<<JobReq[i]<<endl;
        }
    }
    void Details1(){ // details part 1, the split made to reuse the 2 functions in defining Details() for derived classes
        cout<<"Job Title: "<<Title<<endl;
        cout<<"Job Type: "<<(Type?"Remote":"Onsite")<<endl;
    }
    void Details2(){ // details part 2
        cout<<"Minimum Qualification: "<<Qualified(MinQual)<<endl;
        cout<<"Skills Required: "<<endl;
        displaySkills();
        cout<<"Posting: "<<Pdate<<endl;
        cout<<"Deadline: "<<deadline<<endl;
        cout<<"Currently Applied: "<<Applied.size()<<endl;
    }
    virtual void Details(){ // combining 2 parts, virtual function
        Details1();
        Details2();
        cout<<endl;
    }
    Date JobDeadline(){ // member function to read deadline
        return deadline;
    }
    int jqual(){ // member function to read minimum qualification needed
        return MinQual;
    }
    void newapply(Application* apply){ // add new application
        Applied.push_back(apply);
    }
    void newSkill(string skill){ // add new pre-requisite
        JobReq.push_back(skill);
    }
};

class Fulltime: public Job{
public:
    Fulltime(){}
    Fulltime(string post, Date PDate, Date DDate, int sal, int minqual) : Job(post, PDate, DDate, sal, minqual){}
    void Details() override{ // Details in base class overriden
        Details1();
        cout<<"Job Category: Full-time"<<endl;
        cout<<"Salary (in LPA): "<<Salary<<endl;
        Details2();
        cout<<endl;
    }
};

class Parttime: public Job{
    int Duration;
public:
    Parttime(){}
    Parttime(string post, Date PDate, Date DDate, int sal, int minqual, int duration) : Job(post, PDate, DDate, sal, minqual){
        Duration = duration;
    }
    void Details() override{ // details in base class overriden
        Details1();
        cout<<"Job Category: Part-time"<<endl;
        cout<<"Salary (per hour): "<<Salary<<endl;
        cout<<"Work hours/day: "<<Duration<<endl;
        Details2();
        cout<<endl;
    }
};

class Internship: public Job{
    int Duration;
public:
    Internship(){}
    Internship(string post, Date PDate, Date DDate, int sal, int minqual, int duration) : Job(post, PDate, DDate, sal, minqual){
        Duration = duration;
    }
    void Details() override{ //Details in base class overriden
        Details1();
        cout<<"Job Category: Internship"<<endl;
        cout<<"Stipend (in KPM): "<<Salary<<endl;
        cout<<"Duration (in Months): "<<Duration<<endl;
        Details2();
        cout<<endl;
    }
};

class Company{
    string Name, Location, Email, Industry, Phone;
    vector<Job*> postings;
public:
    Company(){}
    Company(string name, string email, string phone, string loc, string industry){
        Name = name;
        Email = email;
        Phone = phone;
        Location = loc;
        Industry = industry;
    }
    void Details(){ // display company details
        cout<<"Name: "<<Name<<endl;
        cout<<"Email: "<<Email<<endl;
        cout<<"Phone: "<<Phone<<endl;
        cout<<"Location: "<<Location<<endl;
        cout<<"Industry: "<<Industry<<endl;
    }
    friend ostream& operator<< (ostream& out, Company C){ // cout<<Company displays company name
        out<<C.Name;
        return out;
    }
    void postJob(Job* job){ // create a new job
        postings.push_back(job);
    }
    void displayJobs(){ // display all jobs listed under company
        for(auto job: postings){
            job->Details();
        }
        cout<<"-------"<<endl;
    }
};

class Application{
protected:
    Seeker S;
    Job* J;
    bool status;
    Date Appdate;
public:
    Application(){}
    Application(Job* job, Seeker applicant, Date ADate){
        S = applicant;
        J = job;
        Appdate = ADate;
        status = false;
        S.newapply(this);
        J->newapply(this);
        status = (Appdate <= J->JobDeadline() && S.squal() >= J->jqual()); // application accepted iff submitted before deadline and satisfies minimum qualification
    }
    bool showstatus(){ // member function to read application status, used to schedule interview
        return status;
    }
    void viewApplication(){// view application in detail
        cout<<"Application Date: "<<Appdate<<endl;
        cout<<"Seeker Details: "<<endl;
        S.Details();
        cout<<"Job Details: "<<endl;
        J->Details();
        cout<<"------------"<<endl;
        cout<<"Application Status: "<<(status?"Accepted":"Rejected")<<endl;
        cout<<"------------"<<endl;
        cout<<"------------"<<endl;
    }
};

class Interview{
    Application A;
    Date date;
    bool Online, Result;
    string feedback;
public:
    Interview(Application apply, Date D, bool mode){
        A = apply;
        if(A.showstatus()){
            date = D;
            Online = mode;
        } else{
            date = Date(0,0,0);
            Online = NULL;
        }
    }
    void setResult(bool R, string F){
        Result = R;
        feedback = F;
    }
};

int main(){
    string K00001("C++");
    string K00002("Java");
    string K00003("Python");
    string K00004("English");

    Seeker S00001("Seishiro Nagi", "nagiofthedead@doogle.com","9823498525",3);
    S00001.newSkill(K00001);
    S00001.newSkill(K00002);
    S00001.Details();

    Seeker S00002("Reo Mikage", "chameleonreo@doogle.com","7833927401",3);
    S00002.newSkill(K00003);
    S00002.Details();

    Seeker S00003("Tsurugi Zantetsu", "bakatensai@doogle.com","8239913487",2);
    S00003.newSkill(K00001);
    S00003.newSkill(K00004);
    S00003.Details();

    Company C00001("Happy Wallet Inc.","admin@happywallet.in","4682368427","Ahmedabad","FinTech");
    Job* J00001 = new Fulltime("Software Engineer", Date(6,11,2024), Date(6,12,2024), 90000, 3);
    Job* J00002 = new Internship("Web Developer", Date(6,11,2024), Date(18,11,2024), 20000, 2, 3);
    Job* J00003 = new Parttime("Telecommunicator", Date(6,11,2024), Date(18,11,2024), 20000, 1, 2);

    J00001->newSkill(K00001);
    J00001->newSkill(K00003);
    J00002->newSkill(K00002);
    J00003->newSkill(K00004);

    C00001.postJob(J00001);
    C00001.postJob(J00002);
    C00001.postJob(J00003);

    Application A00001(J00002, S00001, Date(9,11,2024));
    Application A00002(J00001, S00002, Date(7,12,2024));
    Application A00003(J00001, S00003, Date(8,11,2024));

    C00001.displayJobs();

    A00001.viewApplication();
    A00002.viewApplication();
    A00003.viewApplication();

    delete J00001;
    delete J00002;
    delete J00003;

    return 0;
    return 0;
}

string Qualified(int Q){
    string result;
    switch(Q){
        case 0:
            result = "Below Matriculate";
            break;
        case 1:
            result = "Matriculate";
            break;
        case 2:
            result = "Intermediate/Diploma";
            break;
        case 3:
            result = "Graduate (Bachelor)";
            break;
        case 4:
            result = "Post-Graduate (Master)";
            break;
        case 5:
            result = "Doctorate (PhD)";
            break;
        default:
            result = "N.A.";
            break;
    }
    return result;
}