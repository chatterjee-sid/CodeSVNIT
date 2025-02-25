use dbms_sem3;
drop table if exists customers;
create table customers(
	CID integer primary key auto_increment,
    FirstName varchar(20) not null,
    LastName varchar(20) not null,
    NickName varchar(20),
    Age integer,
    check(age>18),
    EmailID varchar(30) unique not null,
    Bill_Amount numeric(6,2) default 0000.00,
    Bill_Generated datetime not null
);
insert into customers (FirstName, LastName, NickName, Age, EmailID, Bill_Amount, Bill_Generated) values 
('John', 'Doe', 'Johnny', 25, 'john.doe@gmail.com', 1200.50, '2008-11-17 08:52:41'),
('Jane', 'Smith', 'Jane', 30, 'jane.smith@yahoo.com', 800.00, '2008-11-16 19:38:14'),
('Robert', 'Brown', null, 22, 'robert.brown@outlook.com', 450.75, '2008-11-15 14:49:27'),
('Emily', 'Jones', 'Emy', 26, 'emily.jones@gmail.com', 100.25, '2008-11-14 06:29:53'),
('Michael', 'Garcia', null, 35, 'michael.garcia@protonmail.com', 1500.00, '2008-11-13 12:11:58'),
('Sophia', 'Miller', 'Sophie', 28, 'sophia.miller@gmail.com', 920.60, '2008-11-12 16:44:19'),
('David', 'Wilson', 'Dave', 32, 'david.wilson@yahoo.com', 60.00, '2008-11-11 13:23:44'),
('Sarah', 'Taylor', 'Sarah', 29, 'sarah.taylor@outlook.com', 300.90, '2008-11-10 20:58:49'),
('James', 'Moore', 'Jim', 40, 'james.moore@gmail.com', 145.35, '2008-11-09 07:42:11'),
('Jessica', 'Anderson', 'Jess', 27, 'jessica.anderson@yahoo.com', 760.50, '2008-11-08 11:51:38');

-- Table Description
describe customers;

-- 1. Display all the customer names and convert all the customer names to upper-case and give that column name as UCcustomer_names.
select upper(concat_ws(' ',FirstName,LastName)) as UCustomer_names from customers;

-- 2. Remove leading and trailing spaces from customer names and display both, before and after view of customer names as two columns.
select concat_ws(' ',FirstName,LastName) as NameBefore, trim(concat_ws(' ',FirstName,LastName)) as NameAfter from customers;

-- 3. Extract a substring from a string “I am a customer” (start at position 3, extract 5 characters).
select substring("I am a customer",3,5) as subStatement;

-- 4. Email addresses are made up of three basic elements: the username, the "at" sign (@), and the domain name. Return a substring of the email ids of the customers. The substring should contain only the usernames (Use SUBSTRING_INDEX).
select left(EmailID, instr(EmailID,'@')-1) as Username from customers;

-- 5. Compare customer first names and their nicknames and return only those who are having their nicknames same as their first names.
select FirstName from customers where FirstName = Nickname;

-- 6. Return all the customers with their First names, Last names and Full names. (In full names first and last name should be separated by space)
select FirstName, LastName, concat_ws(' ',FirstName,LastName) as FullName from customers;

-- 7. Display all the email ids where .com should be replaced by .in
select replace(EmailID,'.com','.in') as changedMail from customers;

-- 8. Insert the string "You are" into the string “I am a customer" such a way that “I am” should be replaced by “You are”.
select replace("I am a customer","I am","You are") as changedStatements;

-- 9. Format and display the bill amount as "#, ###, ###. ##" (and round with two decimal places).
select format(Bill_amount,2) as Bill from customers;

-- 10. Return the initials of all the customers.
select concat(substring(FirstName,1,1),substring(LastName,1,1)) as Initials from customers;

-- 11. Display the customer whose bill was generated on 2008-11-11 13:23:44.
select * from customers where Bill_Generated = '2008-11-11 13:23:44';