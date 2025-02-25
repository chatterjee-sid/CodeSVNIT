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
select * from Hospital4;
-- Query 2
select DoctorID, DoctorName from Hospital4;
-- Query 3
select DoctorID, DoctorName, Salary, Specialisation from Hospital4 where Specialisation = "Cancer";
-- Query 4
select DoctorID, DoctorName, Salary, Specialisation from Hospital4 where Salary between 50000 and 100000;
-- Query 5
select distinct DoctorName from Hospital4;
-- Query 6
select PatientNo, PatientName from Hospital4 where DoctorName = "XYZ";
-- Query 7
select count(PatientNo) from Hospital4 where Specialisation = "Covid";
-- Query 8
select PatientNo, PatientName from Hospital4 where AdmitDate > "2021-01-01";
-- Query 9
select PatientNo, PatientName from Hospital4 where AdmitDate between "2021-01-01" and "2021-01-31";
-- Query 10
delete from Hospital4 where DoctorName = "ABC";
select * from hospital4;
-- Query 11
update Hospital4 set Doctorname = "ABC" where Doctorname = "XYZ";
select * from hospital4;