use MiniProject;

drop view if exists Interns;
drop view if exists UpcomingInterview;
drop view if exists TopCompanies;
drop view if exists AvailableJobs;
drop trigger if exists newInterview;
drop trigger if exists applicationAccepted;
drop trigger if exists seekerSkillAdd;
drop trigger if exists reqSkillAdd;
drop trigger if exists newpostingadd;
drop procedure if exists setInterviewResult;
drop procedure if exists setInterview;
drop procedure if exists apply;
drop procedure if exists newSeekerSkill;
drop procedure if exists addSkill;
drop procedure if exists newJobSkill;
drop procedure if exists reqSkill;
drop procedure if exists newposting;
drop procedure if exists CompanyProfile;
drop procedure if exists SeekerPhone;
drop procedure if exists SeekerEmail;
drop procedure if exists SeekerProfile;
drop table if exists Interview;
drop table if exists Application;
drop table if exists JobSkill;
drop table if exists SeekerSkill;
drop table if exists SkillSet;
drop table if exists Posting;
drop table if exists Company;
drop table if exists PhoneContacts;
drop table if exists EmailIDs;
drop table if exists Seeker;

create table Seeker(
	SeekerID char(6) primary key,
    SeekerName varchar(25) not null,
    Qualification integer default 0,
    Pass varchar(20) not null
    -- menu describing number related to qualification will be shown, so users will be seeing description, but on system it is treated as a number, to cater for comparison between high qualified and low qualified
);
create table EmailIDs(
	EmailID varchar(25) primary key,
    SeekerID char(6) not null,
    foreign key(SeekerID) references Seeker(SeekerID)
);
create table PhoneContacts(
	Phone char(10) primary key,
    SeekerID char(6) not null,
    foreign key(SeekerID) references Seeker(SeekerID)
);
create table Company(
	CompanyID char(6) primary key,
    CompanyName varchar(25) not null,
    Industry varchar(25) not null,
    Location varchar(25) not null,
    Phone char(10) unique not null,
    Email varchar(25) unique not null,
    Pass varchar(20) not null
);
create table Posting(
	JobID char(6) primary key,
    JobTitle varchar(25) not null,
    JobType varchar(25) not null,
    -- Full time, part time, internship
    Onsite boolean not null,
    JobDescription varchar(250) not null,
    PostingDate date not null,
    Deadline date not null,
    Salary integer not null,
    MinQualification integer not null,
    CompanyID char(6) not null,
    foreign key(CompanyID) references Company(CompanyID)
);
create table SkillSet(
	SkillID char(6) primary key,
    SkillName varchar(25) not null,
    SkillDesc varchar(250) not null
);
create table SeekerSkill(
	SkillID char(6),
    SeekerID char(6),
    primary key(SkillID, SeekerID),
    foreign key(SkillID) references SkillSet(SkillID),
    foreign key(SeekerID) references Seeker(SeekerID)
);
create table JobSkill(
	SkillID char(6),
    JobID varchar(6),
    primary key(SkillID, JobID),
    foreign key(SkillID) references SkillSet(SkillID),
    foreign key(JobID) references Posting(JobID)
);
create table Application(
	ApplicationID char(8) primary key,
    ApplicationDate date not null,
    -- if ADate < Posting.deadline && Seeker.qualification > Posting.minqualification: Appstatus = true, else false
    AppStatus boolean,
    SeekerID char(6) not null,
    JobID char(6) not null,
    foreign key(SeekerID) references Seeker(SeekerID),
    foreign key(JobID) references Posting(JobID)
);
create table Interview(
	InterviewID char(8) primary key,
    InterviewDate date,
    -- online/offline
    IOnline boolean,
    -- pass/fail
    Result boolean,
    Feedback varchar(250),
    ApplicationID char(8) unique not null,
    foreign key(ApplicationID) references Application(ApplicationID)
);

delimiter $$
create procedure SeekerProfile(
	in SeekerName varchar(25),
    in Qualification integer, 
    in email varchar(25), 
    in iphone char(10),
    in pass varchar(20)
) begin
	declare new_id char(6);
    declare existance integer;
	set new_id = (
		select concat('S',lpad(cast(substring(coalesce(max(SeekerID),"S00000"),2) as unsigned) + 1, 5, '0')) from Seeker
	);
    select count(*) into existance
    from EmailIDs
    where EmailID = email;
    if existance > 0
	then
		select "A user with this email already exists" as ErrorMessage;
	else
		select count(*) into existance
		from PhoneContacts
		where Phone = iphone;
		if existance > 0
		then
			select "A user with this phone number already exists" as ErrorMessage;
		else			
			insert into Seeker values
			(new_id, SeekerName, Qualification, pass);
			select concat("Your Seeker Profile has been created. SeekerID: ",new_id) as SuccessMeesage;
			call SeekerEmail(new_id,email);
			call SeekerPhone(new_id,iphone);
		end if;
	end if;
end $$
create procedure SeekerEmail(
	in iSeekerID char(6), 
    in email varchar(25)
) begin
	declare existance integer;
	-- Generally new Email add feature is available on profile only, so it is generally not possible for SeekerID to not exist already
	if iSeekerID not in (
		select SeekerID from Seeker
	) then
		select "This Seeker Profile does not exist, please enter a valid Seeker, or create a profile" as ErrorMessage;
	else
		select count(*) into existance
		from EmailIDs
		where EmailID = email;
		if existance > 0
		then
			select "A user with this email already exists" as ErrorMessage;
		else
			insert into EmailIDs values(email, iSeekerID);
			select "A new email ID has been added to database" as SuccessMessage;
		end if;
	end if;
end $$
create procedure SeekerPhone(
	in iSeekerID char(6), 
    in iphone char(10)
) begin
	declare existance integer;
	-- Generally new Phone add feature is available on profile only, so it is generally not possible for SeekerID to not exist already
	if iSeekerID not in (
		select SeekerID from Seeker
	) then
		select "This Seeker Profile does not exist, please enter a valid Seeker, or create a profile" as ErrorMessage;
	else
		select count(*) into existance
		from PhoneContacts
		where Phone = iphone;
		    if existance > 0
		then
			select "A user with this phone number already exists" as ErrorMessage;
		else
			insert into PhoneContacts values(iphone, iSeekerID);
			select "A new phone number has been added to database" as SuccessMessage;
		end if;
	end if;
end $$
create procedure CompanyProfile(
	in CompanyName varchar(25), 
    in Industry varchar(25), 
    in Location varchar(25), 
    in Phone char(10), 
    in Email varchar(25),
    in pass varchar(20)
) begin
	declare new_id char(6);
    set new_id = (
		select concat('C',lpad(cast(substring(coalesce(max(CompanyID),"C00000"),2) as unsigned) + 1, 5, '0')) from Company
	);
	insert into Company values
    (new_id, CompanyName, Industry, Location, Phone, Email, pass);
    select concat("Your Company Profile has been created. CompanyID: ",new_id) as SuccessMeesage;
end $$
create procedure newposting(
	in CompanyID char(6), 
    in JobTitle varchar(25), 
    in JobType varchar(25), 
    in onsite boolean,
    in JobDesc varchar(250), 
    in deadline date, 
    in salary integer, 
    in minqualification integer
) begin
	declare new_id char(6);
	set new_id = (
		select concat('J',lpad(cast(substring(coalesce(max(JobID),"J00000"),2) as unsigned) + 1, 5, '0')) from Posting
	);
	insert into Posting values
	(new_id, JobTitle, JobType, onsite, JobDesc, curdate(), deadline, salary, minqualification, CompanyID);
    select "New Job Posting added to database" as SuccessMessage;
end $$
create procedure reqSkill(
	in iJobID char(6), 
    in iSkillID char(6)
) begin
	insert into JobSkill values
    (iSkillID, iJobID);
    select "New skill added as Job Requisite" as SuccessMessage;
end $$
create procedure newJobSkill(
	in SkillName varchar(25), 
    in SkillDesc varchar(250), 
    in JobID char(6)
) begin
	declare new_id char(6);
    set new_id = (
		select concat('K',lpad(cast(substring(coalesce(max(SkillID),"K00000"),2) as unsigned) + 1, 5, '0')) from SkillSet
    );
    insert into SkillSet values
    (new_id, SkillName, SkillDesc);
    insert into JobSkill values
    (JobID, new_id);
    select "A new skill has been added to the database, thereby to the job's prerequisites" as SuccessMessage;
end $$
create procedure addSkill(
	in iSeekerID char(6), 
    in iSkillID char(6)
) begin
	insert into SeekerSkill values
    (iSkillID, iSeekerID);
    select "New skill added to your Seeker's skillset" as SuccessMessage;
end $$
create procedure newSeekerSkill(
	in SkillName varchar(25), 
    in SkillDesc varchar(250), 
    in SeekerID char(6)
) begin
	declare new_id char(6);
    set new_id = (
		select concat('K',lpad(cast(substring(coalesce(max(SkillID),"K00000"),2) as unsigned) + 1, 5, '0')) from SkillSet
    );
    insert into SkillSet values
    (new_id, SkillName, SkillDesc);
    insert into SeekerSkill values
    (SeekerID,new_id);
    select "A new skill has been added to the database, thereby to Seeker's skillset" as SuccessMessage;
end $$ 
create procedure apply(
	in iSeekerID char(6), 
    in iJobID char(6)
) begin
	declare new_id char(8);
    set new_id = (
		select concat('A',lpad(cast(substring(coalesce(max(ApplicationID),"A0000000"),2) as unsigned) + 1, 7, '0')) from Application
    );
    insert into Application values
    (new_id,curdate(),true,iSeekerID,iJobID);
    if (
		select AppStatus from Application
        where ApplicationID = new_id
	) = false then
		if (
			select count(*) from Application
            inner join Posting on Application.JobID = Posting.JobID
            where ApplicationID = new_id
            and ApplicationDate <= Deadline
		) = 0 then
			select "Sorry, your application was rejected as it was received post deadline." as RejectMessage;
		elseif (
			select count(*) from Application
            inner join Posting on Application.JobID = Posting.JobID
            inner join Seeker on Application.SeekerID = Seeker.SeekerID
            where ApplicationID = new_id
            and Qualification >= MinQualification
        ) = 0 then
			select "Sorry, your application was rejected as you do not satisfy the minimum qualification needed." as RejectMessage;
		else
			select "Sorry, your application was rejected as you do not possess all of the skills required for this job." as RejectMessage;
		end if;
	else
		select "Congratulations, your application was accepted. You will be notified regarding the interview for this job soon." as AcceptMessage;
	end if;
end $$
create procedure setInterview(
	in iDate date, 
    in imode boolean, 
    in applyID char(8)
) begin
	declare new_id char(8);
	set new_id = (
		select concat('I',lpad(cast(substring(coalesce(max(InterviewID), 'I0000000'),2) as unsigned) + 1, 7, '0')) from Interview
	);
	insert into Interview(InterviewID, InterviewDate, IOnline, ApplicationID) values
	(new_id, iDate, imode, applyID);
    select "A new interview has been scheduled" as SuccessMessage;
end $$
create procedure setInterviewResult(
	in interID char(8), 
    in iRes boolean, 
    in idesc varchar(250)
) begin
	if interID in (
		select InterviewID from Interview
	) then
		update Interview
		set Result = iRes, feedback = idesc
		where InterviewID = interID;
        select "Interview result published" as SuccessMessage;
	else
		select "Interview does not exist" as ErrorMessage;
	end if;
end $$
-- Potential procedures: profile deletion

create trigger newpostingadd
before insert on Posting
for each row
begin
	if new.Deadline < date_add(curdate(),interval 10 day)
    then
		signal sqlstate '45000' set message_text = "Sorry, this posting was not accepted as the deadline must be atleast 10 days after posting date";
	end if;
end $$
create trigger reqSkillAdd
before insert on JobSkill
for each row
begin
	declare existance integer;
    declare missing integer;
    select count(*) into existance
    from JobSkill
    where JobID = new.JobID
    and SkillID = new.SkillID;
    if existance > 0
    then
		signal sqlstate '45000' set message_text = "The Job already has this skill as prerequisite";
	else
		select count(*) into missing
        from SkillSet
        where SkillID = new.SkillID;
        if missing = 0
        then
			signal sqlstate '45000' set message_text = "This Skill does not exist in database."; 
		end if;
	end if;
end $$
create trigger seekerSkillAdd
before insert on SeekerSkill
for each row
begin
	declare existance integer;
    declare missing integer;
    select count(*) into existance
    from SeekerSkill
    where SeekerID = new.SeekerID
    and SkillID = new.SkillID;
    if existance > 0
    then
		signal sqlstate '45000' set message_text = "The Seeker already has this skill";
	else
		select count(*) into missing
        from SkillSet
        where SkillID = new.SkillID;
        if missing = 0
        then
			signal sqlstate '45000' set message_text = "This Skill does not exist in database.";
		end if;
	end if;
end $$
create trigger applicationAccepted
before insert on Application
for each row
begin
	declare dday date;
    declare squal int;
    declare jqual int;
    declare skillissue boolean;
    select deadline into dday
    from Posting
    where JobID = new.JobID;
    select Qualification into squal
    from Seeker
    where SeekerID = new.SeekerID;
    select MinQualification into jqual
    from Posting
    where JobID = new.JobID;
    if NULL in (
		select JobSkill.SkillID from SeekerSkill
        right join JobSkill
        on SeekerSkill.SkillID = JobSkill.SkillID
        where SeekerID = new.SeekerID and JobID = new.JobID
	) then
		set skillissue = true;
	else
		set skillissue = false;
	end if;
    if dday < curdate() or jqual > squal or skillissue = true
    then
		set new.AppStatus = false;
	end if;
end $$
create trigger newInterview
before insert on Interview
for each row
begin
    if new.InterviewDate < date_add(curdate(),interval 10 day)
    then
		signal sqlstate '45000' set message_text = "Sorry, but there must be atleast 10 days gap between scheduling date and interview date";
	elseif new.ApplicationID not in  (
		select ApplicationID from Application
        where AppStatus= true
	) then
		signal sqlstate '45000' set message_text = "Sorry, but no such Accepted application was found.";
	end if;
end $$
delimiter ;

create view UpcomingInterview as
select I.*, J.*, S.* from Interview I
join Application A
on A.ApplicationID = I.ApplicationID
join Posting J
on J.JobID = A.JobID
join Seeker S
on S.SeekerID = A.SeekerID
where InterviewDate >= curdate()
and InterviewDate < date_add(curdate(),interval 7 day);

create view Interns as
select S.*, J.*
from Seeker S
join Application A
on A.SeekerID = S.SeekerID
join Posting J
on A.JobID = J.JobID
join Interview I
on I.ApplicationID = A.ApplicationID
where I.Result = true
and lower(J.JobType) like "internship";

create view TopCompanies as
select C.CompanyID, C.CompanyName, count(P.JobID) as TotalPostings
from Company C
join Posting P
where P.CompanyID = C.CompanyID
group by C.CompanyID
order by TotalPostings desc
limit 10;

create view AvailableJobs as
select P.*, C.CompanyName,C.Industry, C.Location, C.Phone, C.Email
from Posting P
join Company C
on P.CompanyID = C.CompanyID
where deadline >= curdate();