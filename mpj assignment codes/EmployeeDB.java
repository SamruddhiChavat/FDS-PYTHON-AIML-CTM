import java.sql.*;

public class EmployeeDB {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/EmployeeDB";
    private static final String USER = "root";
    private static final String PASSWORD = "password";
    
    public static Connection connect() throws SQLException {
        return DriverManager.getConnection(DB_URL, USER, PASSWORD);
    }

    // Create Employee
    public static void addEmployee(String name, double salary) throws SQLException {
        String query = "INSERT INTO Employees (emp_name, emp_salary) VALUES (?, ?)";
        try (Connection conn = connect(); PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, name);
            stmt.setDouble(2, salary);
            stmt.executeUpdate();
        }
    }

    // Read Employees
    public static ResultSet getEmployees() throws SQLException {
        String query = "SELECT * FROM Employees";
        Connection conn = connect();
        Statement stmt = conn.createStatement();
        return stmt.executeQuery(query);
    }

    // Update Employee
    public static void updateEmployee(int id, String name, double salary) throws SQLException {
        String query = "UPDATE Employees SET emp_name = ?, emp_salary = ? WHERE emp_id = ?";
        try (Connection conn = connect(); PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, name);
            stmt.setDouble(2, salary);
            stmt.setInt(3, id);
            stmt.executeUpdate();
        }
    }

    // Delete Employee
    public static void deleteEmployee(int id) throws SQLException {
        String query = "DELETE FROM Employees WHERE emp_id = ?";
        try (Connection conn = connect(); PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, id);
            stmt.executeUpdate();
        }
    }
}
