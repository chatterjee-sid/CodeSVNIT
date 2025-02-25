use dbms_sem3;
drop table if exists Hospital4;
create table if not exists Hospital4(
	DoctorID integer primary key,
    DoctorName character(25),
    Specialisation character(25),
    Salary integer,
    PatientNo integer,
    PatientName character(25),
    AdmitDate date,
    DischargeDate date
);

insert into Hospital4 values
(1, 'XYZ', 'Cardiology', 70000, 101, 'John Smith', '2020-12-15', '2020-12-20'),
(2, 'ABC', 'Cancer', 60000, 102, 'Jane Doe', '2020-11-10', '2020-11-15'), 
(3, 'DEF', 'Orthopedics', 80000, 103, 'Bob Johnson', '2021-01-05', '2021-01-10'),
(4, 'GHI', 'Orthopedics', 90000, 104, 'Maria Rodriguez', '2020-10-20', '2020-10-25'),
(5, 'JKL', 'Cancer', 55000, 105, 'David Lee', '2021-01-15', '2021-01-20'),
(6, 'MNO', 'Pediatrics', 45000, 106, 'Emily Chen', '2020-09-15', '2020-09-20'),
(7, 'PQR', 'Covid', 65000, 107, 'Michael Brown', '2020-08-10', '2020-08-15'),
(8, 'STU', 'Orthopedics', 75000, 108, 'Sophia Patel', '2021-02-01', '2021-02-05'),
(9, 'VWX', 'Cardiology', 50000, 109, 'Olivia Martin', '2020-07-20', '2020-07-25'),
(10, 'YZA', 'Urology', 40000, 110, 'Benjamin Davis', '2020-06-15', '2020-06-20');

describe Hospital4;
-- Query 1
select DoctorName, Specialisation from Hospital4 order by Specialisation;
-- Query 2 & 3
select Specialisation, count(DoctorName) as NoOfDoctors from Hospital4 group by Specialisation;
-- Query 4
select Specialisation as Diagnosis, count(PatientName) as NoOfPatients from Hospital4 group by Specialisation;
-- Query 5
select DoctorID, DoctorName from Hospital4 where Specialisation not like "Cancer";
-- Query 6
select count(DoctorID) as Doctors from Hospital4 where salary = 50000;
-- Query 7
select PatientNo, PatientName from Hospital4 order by AdmitDate limit 1;
-- Query 8
select avg(PatientCnt) as AveragePatientCnt from (
	select count(PatientNo) as PatientCnt from Hospital4 group by year(AdmitDate), month(AdmitDate)
) as derive;
-- Query 9
select Year, Month, PatientCnt from (
	select year(DischargeDate) as Year, monthname(DischargeDate) as Month, count(PatientNo) as PatientCnt from Hospital4 group by year(DischargeDate), monthname(DischargeDate)
) as derive;
-- Query 10
select count(*) as NoOfPatients from Hospital4 where AdmitDate >= '2020-10-01';
-- Query 11
select Specialisation from (
	select Specialisation, count(*) as numdocs from Hospital4 group by Specialisation
) as derive order by numdocs limit 1;
-- Query 12
select DoctorName from Hospital4 order by salary desc limit 1;
-- Query 13
select Specialisation, avg(salary) as AverageSalary from Hospital4 group by Specialisation;
-- Query 14
select min(patients) as MinPatients from (
	select count(*) as patients from Hospital4 group by Specialisation
) as derive;
-- Query 15
select avg(patients) AvgPatients from (
	select count(*) as patients from Hospital4 group by Specialisation
) as derive;