<!DOCTYPE html>
<html>
<head>
    <title>View Employees</title>
</head>
<body>
    <h2>Employees List</h2>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Salary</th>
        </tr>
        <% 
            ResultSet rs = (ResultSet) request.getAttribute("employees");
            while(rs.next()) {
        %>
        <tr>
            <td><%= rs.getInt("emp_id") %></td>
            <td><%= rs.getString("emp_name") %></td>
            <td><%= rs.getDouble("emp_salary") %></td>
        </tr>
        <% } %>
    </table>
</body>
</html>
