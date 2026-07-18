SELECT employees.name,
emplOyeeuni.unique_id
from employees 
LEFT JOIN employeeuni ON employees.id=employeeuni.id ;