use dbms_sem3;
drop table if exists Sales_data6;
create table Sales_data6(
	order_id integer primary key,
    order_date date,
    product_name varchar(25),
    quantity integer,
    total_price numeric(9,2)
);

insert into Sales_data6 values
(123456, "2022-10-01", "Phone A", 2, 21000.00),
(234567, "2022-10-05", "TV B", 1, 56000.00),
(345678, "2022-12-10", "Shoes C", 3, 16800.00),
(456789, "2022-12-12", "Headphones D", 2, 8400.00),
(567890, "2022-12-15", "Jacket E", 1, 7000.00),
(678901, "2023-03-18", "Watch F", 2, 4200.00),
(789012, "2023-03-20", "Laptop G", 1, 84000.00),
(890123, "2023-03-22", "Camera H", 2, 56000.00),
(901234, "2023-06-25", "Sock I", 5, 300.00),
(012345, "2023-06-28", "Tablet J", 1, 28000.00);

describe Sales_data6;
-- 1. Retrieve the total number of orders placed in the year 2023
select count(order_id) as total_orders_2023 from Sales_data6 where year(order_date)=2023;

-- 2. Calculate the total revenue generated in the month of June 2023.
select sum(total_price) as total_revenue_Jun2023 from Sales_data6 where month(order_date)=6 and year(order_date)=2023;

-- 3. Find the details of order which was placed most recently.
select * from Sales_data6 as latest_order where order_date = (
	select max(order_date) from Sales_data6
);

-- 4. Write a query to display the order date, product name, quantity, and total price for orders placed on weekends (Saturday or Sunday). (Do it using appropriate DATE function and IN operator)
select order_date, product_name, quantity, total_price from Sales_data6 as Weekend_orders having dayofweek(order_date) in (1,7);

-- 5. Calculate the total revenue generated on weekdays (Monday to Friday) in 2023.
select sum(total_price) as total_revenue_business from (
	select * from Sales_data6 having dayofweek(order_date) between 2 and 6
) as weekday_orders;
-- 6. Retrieve the oldest order date in the sales_data table.
select order_date as first_order_date from Sales_data6 where order_date = (
	select min(order_date) from Sales_data6
);