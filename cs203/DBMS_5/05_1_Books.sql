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
('1234567890', 'DBMS Fundamentals', 'Your Name', '2020-05-15', 'English', '2020-06-01', '2020-06-15', 'ABC Publishers', 350.00),
('2345678901', 'Computer Organization', 'Your Name', '2020-08-20', 'English', '2020-09-01', '2020-09-15', null, 450.00),
('3456789012', 'DBMS Concepts', 'Father Name', '2021-01-10', 'English', '2021-01-20', '2021-02-01', 'ABC Publishers', 550.00),
('4567890123', 'Computer Architecture', 'Your Name', '2020-03-15', 'English', '2020-04-01', '2020-04-15', null, 400.00),
('5678901234', 'DBMS Systems', 'Mother Name', '2020-11-20', 'English', '2020-12-01', '2020-12-15', 'XYZ Publishers', 600.00),
('6789012345', 'Computer Networks', 'Mother Name', '2020-02-10', 'English', '2020-03-01', '2020-03-15', null, 300.00),
('7890123456', 'DBMS Applications', 'Father Name', '2021-02-20', 'English', '2021-03-01', '2021-03-15', 'PQR Publishers', 650.00),
('8901234567', 'Computer Graphics', 'Father Name', '2020-06-15', 'English', '2020-07-01', '2020-07-15', 'XYZ Publishers', 500.00),
('9012345678', 'DBMS Design', 'Your Name', '2020-09-20', 'English', '2020-10-01', '2020-10-15', 'ABC Publishers', 420.00),
('0123456789', 'Computer Systems', 'Mother Name', '2020-12-15', 'English', '2021-01-01', '2021-01-15', null, 580.00);

describe Books4;
-- Query 1
select BookTitle, Author, Lang from Books4 order by Lang;
-- Query 2
select ISBN, BookTitle from Books4 order by BookTitle desc;
-- Query 3
select max(Price) as maxPrice, min(Price) as minPrice from Books4;
-- Query 4
select * from Books4 where Author like "Your Name";
-- Query 5
select * from Books4 where Author not like "Father Name";
-- Query 6
select * from Books4 where Price > 500;
-- Query 7
select author from Books4 group by author having count(Publication) > 3;
-- Query 8
select Publisher, BookTitle from Books4 where Price > 250 order by Author;
-- Query 9
select avg(Price) as AveragePrice from Books4 where Author like "Mother Name";
-- Query 10
select Author, avg(Price) as AveragePrice from Books4 group by Author;
-- Query 11
select Publisher, count(BookTitle) as NoOfBooks from Books4 group by Publisher;
-- Query 12
select Author, BookTitle from Books4 order by Price desc limit 1;
-- Query 13
select Author, BookTitle from Books4 order by Price limit 1;
-- Query 14
select Author, BookTitle from Books4 order by Price desc limit 1 offset 1;