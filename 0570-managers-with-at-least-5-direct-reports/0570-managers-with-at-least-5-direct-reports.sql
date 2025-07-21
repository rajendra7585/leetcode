SELECT m.name
FROM employee e
JOIN employee m ON e.managerId = m.id
GROUP BY m.id
HAVING COUNT(e.id) >= 5;
