create database if not exists DBMS_Sem3_Asgn8;
use DBMS_Sem3_Asgn8;

drop procedure if exists part1;
drop procedure if exists part2;
drop procedure if exists part3;
drop procedure if exists part4;
drop table if exists Order_Product;
drop table if exists Orders;
drop table if exists Customer;
drop table if exists Product;
drop table if exists Category;
drop table if exists Merchant;

create table Merchant(
  M_id integer primary key, 
  M_Name varchar(25),
  Rating numeric(2,1),
  check (Rating>=1),
  check (Rating<=5)
);
create table Category(
  Category_id integer primary key,
  Category varchar(25)
);
create table Product(
  Product_id integer primary key, 
  Product varchar(50), 
  Amount integer default 0, 
  Quantity_remaining integer default 0,
  Category_id integer,
  M_id integer,
  foreign key (Category_id) references Category(Category_id),
  foreign key (M_id) references Merchant(M_id)
);
create table Customer(
  Customer_id integer primary key,
  C_name varchar(25),
  C_pass varchar(25)
);
create table Orders(
  Order_id integer primary key,
  Customer_id integer,
  Amount integer default 0,
  ODate date,
  OTime time,
  foreign key (Customer_id) references Customer(Customer_id)
);
create table Order_Product(
  Order_id integer,
  Product_id integer,
  Quantity integer default 0,
  M_id integer,
  Original_amount integer default 0 ,
  Discount integer default 0,
  Product_Rating integer,
  primary key (Order_id, Product_id),
  foreign key (M_id) references Merchant(M_id),
  check (Product_Rating >= 1),
  check (Product_Rating <= 5),
  check (Quantity > 0)
);

insert into Merchant values
(1,"Abhay",3.3),
(2,"Priya",1),
(3,"Kishan",4.8),
(4,"Vicky",4.3),
(5,"Sneha",3.6),
(6,"Pushpa",2.8);

insert into Category values
(1,"Books"),
(2,"Footwear"),
(3,"Home Decor"),
(4,"Accessories");

insert into Product values
(1,"The Programming Langugae of ORACLE",350,4,1,1),
(2,"Nike White Shoes",7000,2,2,3),
(3,"White Lamp",800,3,3,5),
(4,"Antique Silver Earrings",400,7,4,2),
(5,"Antique Silver Bracelet",700,5,4,6),
(6,"Catwalk Leather Flats",1600,3,2,4),
(7,"Introduction to Java",650,8,1,5),
(8,"Portico King size bedsheet",2000,1,3,1),
(9,"Book rack",1000,7,3,4),
(10,"Artificial Intelligence, 3rd Edition",570,9,1,2),
(11,"Introduction to Python",630,10,1,5);

insert into Customer values
(1, "Rohan", "rohan_is_god1"),
(2, "Isha", "74the.genius_pirate"),
(3, "Charlie", "shop.cHarLy"),
(4, "Kritika", "paasuvaado"),
(5, "Rakesh", "rrrakesh113");

insert into Orders values
(1, 2, 7500, '2023-09-16', '14:41:32'),
(2, 3, 450, '2023-10-17', '09:33:23'),
(3, 1, 1300, '2024-07-18', '17:25:45'),
(4, 1, 2000, '2024-09-19', '10:50:11'),
(5, 5, 3000, '2024-10-20', '12:12:54'),
(6, 1, 3500, '2024-11-11', '15:48:21');

insert into Order_Product values
(1, 1, 1, 1, 350, 10, 4),
(1, 4, 2, 2, 400, 0, 2),
(2, 2, 1, 3, 7000, 15, 5),
(3, 1, 1, 5, 800, 5, 3),
(4, 1, 1, 1, 350, 20, 4),
(5, 5, 3, 6, 700, 5, 3);

delimiter $$
create procedure part1()
begin
	declare idstore integer;
	declare num_c integer default 0;
    declare num_m integer default 0;
    declare done boolean default false;
    declare c1 cursor for
		select Customer_id from customer;
	declare c2 cursor for
		select M_id from merchants;
    declare continue handler for not found set done = true;
    open c1;
    counter: loop
		fetch c1 into idstore;
        if done then
			leave counter;
		end if;
        set num_c = num_c + 1;
	end loop;
    close c1;
    set done = false;
    open c2;
    counter: loop
		fetch c2 into idstore;
        if done then 
			leave counter;
        end if;
        set num_m = num_m + 1;
	end loop;
    close c2;
    select num_c as CustomerCount, num_m as SellerCount;
end $$

create procedure part2()
begin
	declare done boolean default false;
    declare id integer;
    declare productname varchar(50);
    declare price integer;
    declare cat varchar(25);
	declare c1 cursor for
		select P.Product_id, P.Product, P.Amount, C. Category
        from Product P
        join Category C
        on P.category_id = C.category_id
        order by Category;
	declare continue handler for not found set done = true;
    open c1;
    products: loop
		fetch c1 into id, productname, price, cat;
        if done then
			leave products;
		end if;
        select id as ProductID, productname as Product, price as Price, cat as Category;
    end loop;
    close c1;
end $$

create procedure part3()
begin
	declare done boolean default false;
	declare id int;
    declare sname varchar(25);
    declare srating numeric(2,1);
    declare c1 cursor for
		select M_id, M_name, Rating from Merchant;
	declare continue handler for not found set done = true;
    open c1;
    seller: loop
		fetch c1 into id, sname, srating;
        if done then
			leave seller;
		end if;
        select id as SellerID, sname as SellerName, srating as Rating;
    end loop;
    close c1;
end $$

create procedure part4()
begin
	declare done boolean default false;
    declare id integer;
    declare highid integer;
    declare pname varchar(50);
    declare highpname varchar(50);
    declare samount integer;
    declare highamount integer default 0;
    declare c1 cursor for
		select Product_id, Product, Amount from Product;
	declare continue handler for not found set done = true;
    open c1;
    highest: loop
		fetch c1 into id, pname, samount;
        if done then
			leave highest;
		end if;
        if samount > highamount then
			set highid = id;
            set highpname = pname;
            set highamount = samount;
		end if;
	end loop;
    close c1;
    select highid as ProductID, highpname as Product, highamount as Amount;
end $$
delimiter ;