CREATE DATABASE IF NOT EXISTS dbms_sem3_labexam;
USE dbms_sem3_labexam;

DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS salesman;

CREATE TABLE salesman(
    salesman_id INT PRIMARY KEY,
    name VARCHAR(25),
    city VARCHAR(25),
    commission NUMERIC(3,2)
);

INSERT INTO salesman VALUES
(5001, "James Hooq", "New York", 0.15),
(5002, "Nail Knite", "Paris", 0.13),
(5005, "Pit Alex", "London", 0.11),
(5006, "Mc Lyon", "Paris", 0.14),
(5003, "Lauson Hen", NULL, 0.12),
(5007, "Paul Adam", "Rome", 0.13);

CREATE TABLE customer(
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(25),
    city VARCHAR(25),
    grade INT,
    salesman_id INT,
    FOREIGN KEY(salesman_id) REFERENCES salesman(salesman_id)
);

INSERT INTO customer VALUES
(3002, "Nick Rimando", "New York", 100, 5001),
(3005, "Graham Zusi", "California", 200, 5002),
(3001, "Brad Guzan", "London", NULL, NULL),
(3004, "Fabian Johns", "Paris", 300, 5006),
(3007, "Brad Davis", "New York", 200, 5001),
(3009, "Geoff Camero", "Berlin", 100, NULL),
(3008, "Julian Green", "London", 300, 5002),
(3003, "Jozy Altidor", "Moscow", 200, 5007);

CREATE TABLE orders(
    order_no INT PRIMARY KEY,
    purch_amt NUMERIC(6,2),
    order_date DATE,
    customer_id INT,
    salesman_id INT,
    FOREIGN KEY(customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY(salesman_id) REFERENCES salesman(salesman_id)
);

INSERT INTO orders VALUES
(70001, 150.5, "2016-10-05", 3005, 5002),
(70009, 270.65, "2016-09-10", 3001, NULL),
(70002, 65.26, "2016-10-05", 3002, 5001),
(70004, 110.5, "2016-08-17", 3009, NULL),
(70007, 948.5, "2016-09-10", 3005, 5002),
(70005, 2400.6, "2016-07-27", 3007, 5001),
(70008, 5760, "2016-09-10", 3002, 5001),
(70010, 1983.43, "2016-10-10", 3004, 5006),
(70003, 2480.4, "2016-10-10", 3009, NULL),
(70012, 250.45, "2016-06-27", 3008, 5002),
(70011, 75.29, "2016-08-17", 3003, 5007);

-- 1. Problem related to nobel winners DB: Unrelated to Test
-- 2. Find the highest purchase amount with their customer ID and order date, for only those customers who have the highest purchase amount in a day is more than 2000.
SELECT customer_id AS 'Customer ID', MAX(purch_amt) AS 'Highest Purchase Amount', order_date AS 'Order Date'
FROM orders
WHERE purch_amt > 2000
GROUP BY 'Customer ID';

-- 3. Display of name and cost of cheapest item: Unrelated to Test
-- 4. Display all the customers, who are either belongs to the city New York or not had a grade above 100.
SELECT * FROM customer
WHERE city LIKE "New York"
OR grade <= 100;

-- 5. Find the highest purchase amount ordered by each customer on a particular date with their ID, order date and highest purchase amount.
DROP PROCEDURE IF EXISTS highest_purchase0;
DELIMITER $$
CREATE PROCEDURE highest_purchase0(IN cid INT, IN odate DATE)
BEGIN
    DECLARE purchase INT;
    SET purchase = (
	    SELECT MAX(purch_amt)
    	FROM orders
    	WHERE customer_id = cid AND order_date = odate
    );
    SELECT cid AS 'Customer ID', odate AS 'Order Date', purchase AS 'Highest Purchase Amount';
END $$
DELIMITER ;
CALL highest_purchase0(3005, "2016-10-05");
CALL highest_purchase0(3005, "2016-10-10");

-- 5x. Same, but with cursor (additional)
DROP PROCEDURE IF EXISTS highest_purchase;
DELIMITER $$
CREATE PROCEDURE highest_purchase(IN cid INT, IN odate DATE)
BEGIN
    DECLARE done BOOL DEFAULT FALSE;
    DECLARE purchase NUMERIC(6,2);
    DECLARE highpurchase NUMERIC(6,2) DEFAULT 0;
    DECLARE cur CURSOR FOR
    	SELECT purch_amt
        FROM orders
        WHERE customer_id = cid AND order_date = odate;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    OPEN cur;
    highest: LOOP
    	FETCH cur INTO purchase;
        IF done THEN
        	LEAVE highest;
        END IF;
        IF purchase > highpurchase THEN
        	SET highpurchase = purchase;
        END IF;
    END LOOP;
    CLOSE cur;
    IF highpurchase > 0 THEN
    	SELECT cid AS 'Customer ID', odate AS 'Order Date', highpurchase AS 'Highest Purchase Amount';
    ELSE
    	SELECT cid AS 'Customer ID', odate AS 'Order Date', NULL AS 'Highest PurchASe Amount';
    END IF;
END $$
DELIMITER ;
CALL highest_purchase(3005, "2016-10-05");
CALL highest_purchase(3005, "2016-10-10");