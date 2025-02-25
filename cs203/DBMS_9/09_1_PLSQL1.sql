use dbms_sem3;

-- 1. Write a pl/sql program to get the area of the circle provided the radius is given.
drop procedure if exists Area;
delimiter $$
create procedure Area(in radius integer)
begin
	declare area double;
	set area = pi()*radius*radius;
    select area;
end $$
delimiter ;

call area(5);

-- 2. Write a pl/sql program to get the name and salary of specified employee.
drop procedure if exists employeeDetail;
drop table if exists employee;
create table employee(
	eid integer primary key,
    ename varchar(25),
    salary numeric(7,2)
);
insert into employee values
(1,"A",1000),
(2,"B",2000),
(3,"C",4000),
(4,"D",5000);
delimiter $$
create procedure employeeDetail(in ineid integer)
begin
	if ineid in (
		select eid from employee
	) then
		select ename, salary
		from employee
		where eid =  ineid;
	else
	 	select null as ename, null as salary;
	end if;
end $$
delimiter ;
call employeeDetail(4);
call employeeDetail(5);

-- 3. Write a PL/SQL program to arrange the number of two variable in such a way that the small number will store in num_small variable and large number will store in num_large variable.
drop procedure if exists bigsmall;
delimiter $$
create procedure bigsmall(in num1 integer, in num2 integer)
begin
	declare num_small integer;
    declare num_big integer;
    if num1 < num2 then
		set num_small = num1;
        set num_big = num2;
	else
		set num_small = num2;
        set num_big = num1;
	end if;
	select num_small, num_big;
end $$
delimiter ;
call bigsmall(5,3);
call bigsmall(5,8);

-- 4. Write a pl/sql program Accept Number from a User and display Hello message if the entered number is Positive.
drop procedure if exists hello;
delimiter $$
create procedure hello(in num integer)
begin
	if num>0 then
		select "Hello user!" as Hello_messager;
	end if;
end $$
delimiter ;
call hello(5);
call hello(-5);

-- 5. Write a pl/sql program to Display Salary of a specified employee increasing by 500 if its salary is more than 3000.
drop procedure if exists increment;
delimiter $$
create procedure increment(in ineid integer)
begin
	declare S numeric(7,2);
    set S = (
		select salary
        from employee
        where eid = ineid
	);
    if S > 3000 then
		select eid, salary+500 as salary
        from employee
        where eid = ineid;
	else
		select eid, salary
        from employee
        where eid = ineid;
	end if;
end $$
delimiter ;
call increment(2);
call increment(3);
    
-- 6. Write a pl/sql program to Accept number from a user and find out whether it is Odd or Even.
drop procedure if exists oddeven;
delimiter $$
create procedure oddeven(in num integer)
begin
	if num<0 then
		select "Negative" as Numtype;
	else
		if num%2 = 0 then
			select "Even" as Numtype;
		else
			select "Odd" as Numtype;
		end if;
	end if;
end $$
delimiter ;
call oddeven(2);
call oddeven(3);
call oddeven(1);
call oddeven(-1);

-- 7. Write a pl/sql program to accept employee number from a user and increase its salary depends on the current salary as follows. Salary Increment: >= 5000 12.5%; <5000 11%;
drop procedure if exists hardincrement;
delimiter $$
create procedure hardincrement(in ineid integer)
begin
	declare S numeric(7,2);
    declare increment numeric(4,3);
    set S = (
		select salary
        from employee
        where eid = ineid
	);
    if S>=5000 then
		set increment = 1.125;
	else
        set increment = 1.11;
	end if;
	update employee
	set salary = salary * increment
	where eid = ineid;
end $$
delimiter ;
call hardincrement(1);
call hardincrement(4);
select * from employee;

-- 8. Write a pl / sql program by using Iterative Control / Loops to Accept number from a user and find out its factorial.
drop procedure if exists factorial;
delimiter $$
create procedure factorial (in num integer)
begin
	declare i integer;
    declare res integer;
    set i = 1;
    set res = 1;
    factorial_loop: loop
		if i > num then
			leave factorial_loop;
		end if;
        set res = res * i;
        set i = i + 1;
	end loop;
    if num >= 0 then
		select num as Num, res as Factorial;
	else
		select num as Num, null as Factorial;
	end if;
end $$
delimiter ;
call factorial(4);
call factorial(7);
call factorial(-1);