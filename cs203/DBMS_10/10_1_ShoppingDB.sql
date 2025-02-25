create database if not exists DBMS_Sem3_Asgn8;
use DBMS_Sem3_Asgn8;

drop table if exists Order_Products;
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
create table Order_Products(
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

delimiter $$
create trigger QuantityUpdates
after insert on order_products
for each row
begin
	update Product
	set Quantity_remaining = Quantity_remaining - new.Quantity
	where Product_id = new.Product_id;
end$$

create trigger RatingUpdate
after insert on order_products
for each row
begin
	declare newmrate numeric(2,1);
    -- declare newprate numeric(2,1);
	set newmrate = (
		select avg(Product_Rating)
        from order_products
        where M_id = new.M_id
	);
    -- set newprate = (
-- 		select avg(Product_Rating)
--         from order_products
--         where Product_id = new.Product_id
--     );
    update Merchant
    set Rating = newmrate
    where M_id = new.M_id;
end$$

create trigger QuantityCheck
before insert on order_products
for each row
begin
    if new.Quantity > (
		select Quantity_remaining
        from Product
        where Product_id = new.Product_id
	)
    then
        signal sqlstate '45000' set message_text = "Out of stock";
	end if;
end $$
delimiter ;
select * from order_products;
select * from Product;
select * from Merchant;

insert into order_products values
(1, 1, 1, 1, 350, 10, 4),
(1, 4, 2, 2, 400, 0, 2),
(2, 2, 1, 3, 7000, 15, 5),
(3, 1, 1, 5, 800, 5, 3),
(4, 1, 1, 1, 350, 20, 4),
(5, 5, 3, 6, 700, 5, 3);
-- (6, 1, 5, 1, 350, 10, 3);

select * from order_products;
select * from Product;
select * from Merchant;