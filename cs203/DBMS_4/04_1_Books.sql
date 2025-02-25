use dbms_sem3;
drop table if exists Books4;
create table Books4(
	ISBN character(10) primary key,
    BookTitle character(25),
    Author character(25),
    Publication date,
    Lang character(25),
    IssueDate date,
    ReturnDate date,
    Publisher character(25) default null,
    Price numeric(7,2)
);

insert into Books4 values
('1234567890', 'DBMS Fundamentals', 'John Smith', '2020-05-15', 'English', '2020-06-01', '2020-06-15', 'ABC Publishers', 350.00),
('2345678901', 'Computer Organization', 'Jane Doe', '2020-08-20', 'English', '2020-09-01', '2020-09-15', null, 450.00),
('3456789012', 'DBMS Concepts', 'Michael Brown', '2021-01-10', 'English', '2021-01-20', '2021-02-01', 'ABC Publishers', 550.00),
('4567890123', 'Computer Architecture', 'Emily Johnson', '2020-03-15', 'English', '2020-04-01', '2020-04-15', null, 400.00),
('5678901234', 'DBMS Systems', 'David Lee', '2020-11-20', 'English', '2020-12-01', '2020-12-15', 'XYZ Publishers', 600.00),
('6789012345', 'Computer Networks', 'Sophia Patel', '2020-02-10', 'English', '2020-03-01', '2020-03-15', null, 300.00),
('7890123456', 'DBMS Applications', 'Olivia Martin', '2021-02-20', 'English', '2021-03-01', '2021-03-15', 'PQR Publishers', 650.00),
('8901234567', 'Computer Graphics', 'Ava Garcia', '2020-06-15', 'English', '2020-07-01', '2020-07-15', 'XYZ Publishers', 500.00),
('9012345678', 'DBMS Design', 'Ethan Hall', '2020-09-20', 'English', '2020-10-01', '2020-10-15', 'ABC Publishers', 420.00),
('0123456789', 'Computer Systems', 'Lily Chen', '2020-12-15', 'English', '2021-01-01', '2021-01-15', null, 580.00);

describe Books4;
-- Query 1
select * from Books4;
-- Query 2
select * from Books4 order by price;
-- Query 3
select * from Books4 where price between 250 and 700;
-- Query 4
select * from Books4 where price > 500;
-- Query 5
select Publication, Publisher from Books4 where Publication > "2021-01-01";
-- Query 6
select * from Books4 where Publisher is null;
-- Query 7
select count(*) from Books4 where Publisher is not null;
-- Query 8
alter table Books4 rename column Author to AuthorName;
describe Books4;
-- Query 9
alter table Books4 add column BorrowerName character(25);
describe Books4;
-- Query 10
alter table Books4 drop column BorrowerName;
describe Books4;