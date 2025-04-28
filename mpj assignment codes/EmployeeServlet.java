import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class EmployeeServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String action = request.getParameter("action");

        if ("view".equals(action)) {
            try {
                ResultSet rs = EmployeeDB.getEmployees();
                request.setAttribute("employees", rs);
                RequestDispatcher dispatcher = request.getRequestDispatcher("viewEmployees.jsp");
                dispatcher.forward(request, response);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String action = request.getParameter("action");

        if ("add".equals(action)) {
            String name = request.getParameter("emp_name");
            double salary = Double.parseDouble(request.getParameter("emp_salary"));

            try {
                EmployeeDB.addEmployee(name, salary);
                response.sendRedirect("index.jsp");
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
