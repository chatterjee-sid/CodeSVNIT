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
(4,"Vivky",4.3),
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
(5, 5, 3000, '2024-10-20', '12:12:54');

insert into Order_Products values
(1, 1, 1, 1, 350, 10, 4),
(1, 4, 2, 2, 400, 0, 2),
(2, 2, 1, 3, 7000, 15, 5),
(3, 1, 1, 5, 800, 5, 3),
(4, 1, 1, 1, 350, 20, 4),
(5, 5, 3, 6, 700, 5, 3);

select * from Merchant;
select * from Category;
select * from Product;
select * from Customer;
select * from Orders;
select * from Order_Products;

-- 1. Display the lowest sold product
with B as (
  select product_id, sum(Quantity) as totalOrders 
  from Order_Products 
  group by product_id
) select A.*
from Product as A
join B
on A.product_id = B.product_id
where B.totalOrders = (
  select min(totalOrders)
  from B
);

-- 2. Add a new seller with all details.
insert into Merchant values
(7,"Pritam",2.5);
select * from Merchant;

-- 3. Add a new product with all details.
insert into Product values
(12, "Higher Engineering Mathematics", 900, 8, 1, 7);
select * from Product;

-- 4. Add a new category with all details.
insert into Category values
(5, "Edibles");
select * from Category;

-- 5. Display the details of the products which have never sold.
select *
from Product
where Product_id not in (
  select Product_id
  from Order_Products
);

-- 6. Display the details of the merchant who has not sold any product today.
select distinct *
from Merchant
where M_id not in (
    select A.M_id
    from Merchant as A
    left join Order_Products as B
    on A.M_id = B.M_id
    left join Orders as C
    on B.Order_id = C.Order_id
    where C.ODate = CURDATE();
);

-- 7. Display the details of the merchant who has sold the highest amount of products today.
with B as (
  select M_id, sum(Original_amount*(1-Discount*0.01)) as DAmount
  from Order_Products
  join Orders
  on Order.Order_id = Order_Products.Order_id
  group by M_id
  where ODate = curdate()
) select A.*, B.DAmount
from Merchant as A
join B
on A.M_id = B.M_id
where B.DAmount = (
  select max(DAmount)
  from B
);

-- 8. Display the merchant details with the highest rating.
select *
from Merchant
where Rating = (
  select max(Rating)
  from Merchant
);

-- 9. Display the customer detail who has repeated the same product purchase in the last four months.
with Customer_order as (
  select Orders.Customer_id, Order_Products.Product_id, Orders.ODate
  from Orders
  join Order_Products
  on Orders.Order_id = Order_Products.Order_id
) select *
from Customer
where Customer_id in (
  select A.Customer_id
  from Customer_order A
  join Customer_order B
  on A.Customer_id = B.Customer_id
  and A.Product_id = B.Product_id
  where A.ODate > date_sub(curdate(), interval 4 month)
  and B.ODate > date_sub(curdate(), interval 4 month)
  and A.ODate > B.ODate
);

-- 10. Display the merchant details who is third highest in selling products in the last two months.
with A as (
  select Order_Products.M_id, Order_Products.Quantity
  from Order_Products
  join Orders
  on Order_Products.order_id = Orders.order_id
  where Orders.ODate > date_sub(curdate(), interval 2 month)
), B as (
  select M_id, sum(Quantity) as totalOrders
  from A
  group by M_id
) select *
from Merchant
where M_id in (
  select M_id
  from B
  order by totalOrders desc
  offset 2
  limit 1
);

-- 11. Display the list of products having quantity remaining <=5.
select Product
from Product
where Quantity_remaining <= 5;

-- 12. Add a new column “Address” to the merchant table.
alter table Merchant
add column Address varchar(50);
select * from Merchant;

-- 13. Create a table Old_Orders from the Orders table.
-- 14. Insert values from Orders table to Old_Orderss having year < current year.
drop table if exists Old_orders;
create table Old_orders as (
  select *
  from Orders
  where year(ODate) < year(curdate())
);
select * from Old_orders;