# Write your MySQL query statement below
select unique_id, name from Employees as e left outer join EmployeeUNI as eu on e.id = eu.id; 