import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SimpleCalculator extends JFrame implements ActionListener {
    private JTextField tf1, tf2, tfResult;
    private JButton addBtn, subBtn, mulBtn, divBtn, clearBtn;

    public SimpleCalculator() {
        // Frame settings
        setTitle("Simple Calculator");
        setSize(400, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(6, 2, 10, 10));  // Increase row count to accommodate the Clear button

        // Components
        tf1 = new JTextField();
        tf2 = new JTextField();
        tfResult = new JTextField();
        tfResult.setEditable(false);

        addBtn = new JButton("Add");
        subBtn = new JButton("Subtract");
        mulBtn = new JButton("Multiply");
        divBtn = new JButton("Divide");
        clearBtn = new JButton("Clear");

        // Add components to frame
        add(new JLabel("Enter First Number:"));
        add(tf1);
        add(new JLabel("Enter Second Number:"));
        add(tf2);
        add(addBtn);
        add(subBtn);
        add(mulBtn);
        add(divBtn);
        add(new JLabel("Result:"));
        add(tfResult);
        add(clearBtn);  // Add the clear button here to fit the layout

        // Button Action Listeners
        addBtn.addActionListener(this);
        subBtn.addActionListener(this);
        mulBtn.addActionListener(this);
        divBtn.addActionListener(this);
        clearBtn.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            double num1 = Double.parseDouble(tf1.getText());
            double num2 = Double.parseDouble(tf2.getText());
            double result = 0;

            if (e.getSource() == addBtn) {
                result = num1 + num2;
            } else if (e.getSource() == subBtn) {
                result = num1 - num2;
            } else if (e.getSource() == mulBtn) {
                result = num1 * num2;
            } else if (e.getSource() == divBtn) {
                if (num2 == 0) {
                    JOptionPane.showMessageDialog(this, "Cannot divide by zero.");
                    return;
                }
                result = num1 / num2;
            }
            tfResult.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Invalid Input! Please enter valid numbers.");
        }

        if (e.getSource() == clearBtn) {
            tf1.setText("");
            tf2.setText("");
            tfResult.setText("");
        }
    }

    public static void main(String[] args) {
        SimpleCalculator calc = new SimpleCalculator();
        calc.setVisible(true);
    }
}
