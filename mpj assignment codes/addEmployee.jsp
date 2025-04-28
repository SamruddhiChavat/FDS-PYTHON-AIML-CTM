<!DOCTYPE html>
<html>
<head>
    <title>Add Employee</title>
</head>
<body>
    <h2>Add Employee</h2>
    <form action="employee" method="post">
        <input type="hidden" name="action" value="add">
        Employee Name: <input type="text" name="emp_name"><br>
        Employee Salary: <input type="text" name="emp_salary"><br>
        <input type="submit" value="Add Employee">
    </form>
</body>
</html>
