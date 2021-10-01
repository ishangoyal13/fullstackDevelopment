//Importing all necessary libraries
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

//PointCalc class extending JFrame and implementing ActionListener

public class PointCalc extends JFrame implements ActionListener {
	JTextField tfield;
	//declaring and initializing variables
	int l = 0,a = 0,b = 0,x = 0,y = 0 ;

	char ch;

	//creating temp and res instances
	Calc t1 = new Calc();
	Calc t2 = new Calc();
	Calc res = new Calc();

	double scl;

	//declaring buttons	
	JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, zero, clear, add, smulti, equal, dot, addsubtract, 
			eucldist, manhdist, slope, quad, xProjection, yProjection, xReflection, yReflection, openbracket, closedBracket, comma , equl;

	//Creates a container
	Container cont;

	//Creates a JPanel
	JPanel textPanel, buttonpanel;

	//Constructor
	PointCalc() {
		cont = getContentPane();
		cont.setLayout(new BorderLayout());
		JPanel textpanel = new JPanel();
		tfield = new JTextField(35);
		tfield.setHorizontalAlignment(SwingConstants.RIGHT);
		tfield.addKeyListener(new KeyAdapter() {
			public void keyTyped(KeyEvent keyevent) {
				char c = keyevent.getKeyChar();
				if (c >= '0' && c <= '9') {
				} else {
					keyevent.consume();
				}
			}
		});

		//Adds a text field to the calculator face
		textpanel.add(tfield);

		//Adds buttons to the calculator face
		buttonpanel = new JPanel();
		buttonpanel.setLayout(new GridLayout(7, 4, 2, 2));
		
		openbracket = new JButton("(");
		buttonpanel.add(openbracket);
		openbracket.addActionListener(this);

		closedBracket = new JButton(")");
		buttonpanel.add(closedBracket);
		closedBracket.addActionListener(this);
		
		b1 = new JButton("1");
		buttonpanel.add(b1);
		b1.addActionListener(this);
		
		b2 = new JButton("2");
		buttonpanel.add(b2);
		b2.addActionListener(this);
		
		b3 = new JButton("3");
		buttonpanel.add(b3);
		b3.addActionListener(this);

		b4 = new JButton("4");
		buttonpanel.add(b4);
		b4.addActionListener(this);
		
		b5 = new JButton("5");
		buttonpanel.add(b5);
		b5.addActionListener(this);
		
		b6 = new JButton("6");
		buttonpanel.add(b6);
		b6.addActionListener(this);

		b7 = new JButton("7");
		buttonpanel.add(b7);
		b7.addActionListener(this);
		
		b8 = new JButton("8");
		buttonpanel.add(b8);
		b8.addActionListener(this);
		
		b9 = new JButton("9");
		buttonpanel.add(b9);
		b9.addActionListener(this);

		zero = new JButton("0");
		buttonpanel.add(zero);
		zero.addActionListener(this);
		
		comma = new JButton(",");
		buttonpanel.add(comma);
		comma.addActionListener(this);
		
		dot = new JButton(".");
		buttonpanel.add(dot);
		dot.addActionListener(this);
		
		addsubtract = new JButton("-");
		buttonpanel.add(addsubtract);
		addsubtract.addActionListener(this);
		
		equal = new JButton("=");
		buttonpanel.add(equal);
		equal.addActionListener(this);

		quad =  new JButton("Quadrant");
		buttonpanel.add(quad);
		quad.addActionListener(this);
		
		add = new JButton("Add");
		buttonpanel.add(add);
		add.addActionListener(this);

		smulti = new JButton("Scalar Mul");
		buttonpanel.add(smulti);
		smulti.addActionListener(this);

				
		eucldist = new JButton("Euclidian Dist");
		buttonpanel.add(eucldist);
		eucldist.addActionListener(this);

		manhdist = new JButton("Manhattan Dist");
		buttonpanel.add(manhdist);
		manhdist.addActionListener(this);
		
		slope = new JButton("Slope");
		buttonpanel.add(slope);
		slope.addActionListener(this);
		
		xProjection = new JButton("X Proj");
		buttonpanel.add(xProjection);
		xProjection.addActionListener(this);
		
		yProjection =  new JButton("Y Proj");
		buttonpanel.add(yProjection);
		yProjection.addActionListener(this);
		
		xReflection = new JButton("X Refl");
		buttonpanel.add(xReflection);
		xReflection.addActionListener(this);
		
		yReflection =  new JButton("Y Refl");
		buttonpanel.add(yReflection);
		yReflection.addActionListener(this);
		
		equl =  new JButton("Equ line");
		buttonpanel.add(equl);
		equl.addActionListener(this);
		
		clear = new JButton("AC");
		buttonpanel.add(clear);
		clear.addActionListener(this);
		
		cont.add("Center", buttonpanel);
		cont.add("North", textpanel);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	//Performs the action when each button is pressed
	public void actionPerformed(ActionEvent e) {
		String s = e.getActionCommand();
		if (s.equals("1")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "1");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "1");
				l = 0;
			}
		}
		if (s.equals("2")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "2");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "2");
				l = 0;
			}
		}
		if (s.equals("3")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "3");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "3");
				l = 0;
			}
		}
		if (s.equals("4")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "4");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "4");
				l = 0;
			}
		}
		if (s.equals("5")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "5");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "5");
				l = 0;
			}
		}
		if (s.equals("6")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "6");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "6");
				l = 0;
			}
		}
		if (s.equals("7")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "7");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "7");
				l = 0;
			}
		}
		if (s.equals("8")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "8");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "8");
				l = 0;
			}
		}
		if (s.equals("9")) {
			
			if (l == 0) {
				tfield.setText(tfield.getText() + "9");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "9");
				l = 0;
			}
		}
		if (s.equals("0")) {
			if (l == 0) {
				tfield.setText(tfield.getText() + "0");
			} else {
				tfield.setText("");
				tfield.setText(tfield.getText() + "0");
				l = 0;
			}
		}
		if (s.equals("(")) {
			if (l == 0) {
					tfield.setText("" + "(");
				} else {
					tfield.setText("");
					tfield.setText(tfield.getText() + "(");
					l = 0;
				}
				b=1;
			}
		
		if (s.equals(")")) {
			if(b==2) {
				if (l == 0) {
					tfield.setText(tfield.getText() + ")");
				} else {
					tfield.setText("");
					tfield.setText(tfield.getText() + ")");
					l = 0;
				}
				b=0;
			}
		}
		if (s.equals(",")) {
			if(b==1) {
				if (l == 0) {
					tfield.setText(tfield.getText() + ",");
				} else {
					tfield.setText("");
					tfield.setText(tfield.getText() + ",");
					l = 0;
				}
				b=2;
			}
		}
		if (s.equals("AC")) {
			tfield.setText("");
			l = 0;
			y = 0;
			x = 0;
			a = 0;
			b = 0;
		}
		if (s.equals("-")) {
			if (x == 0 || x ==1) {
				tfield.setText(tfield.getText()+"-" );
				x++;
			} else {
				tfield.setText(tfield.getText());
			}
		}
		if (s.equals(".")) {
			if (y == 0 || y ==1) {
				tfield.setText(tfield.getText() + ".");
				y++;
			} else {
				tfield.setText(tfield.getText());
			}
		}
		if (s.equals("Add")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
				ch = '+';
			} else {
				String aa = tfield.getText();
				tfield.setText("");
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				ch = '+';
				y = 0;
				x = 0;
			}
			tfield.requestFocus();
		}
		if (s.equals("Slope")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
				ch = 's';
			} else {
				String aa = tfield.getText();
				tfield.setText("");
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				ch = 's';
				y = 0;
				x = 0;
			}
		}
		if (s.equals("Equ. line")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
				ch = 'l';
			} else {
				String aa = tfield.getText();
				tfield.setText("");
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				ch = 'l';
				y = 0;
				x = 0;
			}
		}
		if (s.equals("Manh. Dist")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
				ch = 'm';
			} else {
				String aa = tfield.getText();
				tfield.setText("");
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				ch = 'm';
				y = 0;
				x = 0;
			}
			
		}
		if (s.equals("Eucl. Dist")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
				ch = 'e';
			} else {
				String aa = tfield.getText();
				tfield.setText("");
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				ch = 'e';
				y = 0;
				x = 0;
			}
			
		}
		if (s.equals("Sca. Mul")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
				ch = '*';
			} else {
				String aa = tfield.getText();
				tfield.setText("");
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				x = 0;
				y = 0;
				ch = '*';
			}
		}
		if (s.equals("Quadrant")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
			} else {
				String aa = tfield.getText();
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				tfield.setText("Q"+t1.knowQuadrant());
			}
		}
		if (s.equals("X Proj")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
			} else {
				String aa = tfield.getText();
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				tfield.setText(t1.xProjection().toString());
			}
		}
		if (s.equals("Y Proj")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
			} else {
				String aa = tfield.getText();
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				tfield.setText(t1.yProjection().toString());
			}
		}
		if (s.equals("X Refl")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
			} else {
				String aa = tfield.getText();
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				tfield.setText(t1.xRef().toString());
			}
		}
		if (s.equals("Y Refl")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
				t1.setX(0);
				t1.setY(0);
			} else {
				String aa = tfield.getText();
				String[] cord = aa.substring(1, aa.length()-1).split(",");
				t1.setX(Double.parseDouble(cord[0]));
				t1.setY(Double.parseDouble(cord[1]));
				tfield.setText(t1.yRef().toString());
			}
		}
		if (s.equals("=")) {
			if (tfield.getText().equals("")) {
				tfield.setText("");
			} else {
				if(ch == '+') {
					String aa = tfield.getText();
					String[] cord = aa.substring(1, aa.length()-1).split(",");
					t2.setX(Double.parseDouble(cord[0]));
					t2.setY(Double.parseDouble(cord[1]));
					tfield.setText(t1.sum(t2).toString());
					l = 1;
				}
				if(ch == '*') {
					scl = Double.parseDouble(tfield.getText());
					tfield.setText(t1.scalarMultiple(scl).toString());
					l = 1;
				}
				if(ch == 'm') {
					String aa = tfield.getText();
					String[] cord = aa.substring(1, aa.length()-1).split(",");
					t2.setX(Double.parseDouble(cord[0]));
					t2.setY(Double.parseDouble(cord[1]));
					tfield.setText(""+t1.distanceM(t2));
				}
				if(ch == 'e') {
					String aa = tfield.getText();
					String[] cord = aa.substring(1, aa.length()-1).split(",");
					t2.setX(Double.parseDouble(cord[0]));
					t2.setY(Double.parseDouble(cord[1]));
					tfield.setText(""+t1.distanceE(t2));
				}
				if(ch == 's') {
					String aa = tfield.getText();
					String[] cord = aa.substring(1, aa.length()-1).split(",");
					t2.setX(Double.parseDouble(cord[0]));
					t2.setY(Double.parseDouble(cord[1]));
					tfield.setText(""+t1.slope(t2));
				}
				if(ch == 'l') {
					String aa = tfield.getText();
					String[] cord = aa.substring(1, aa.length()-1).split(",");
					t2.setX(Double.parseDouble(cord[0]));
					t2.setY(Double.parseDouble(cord[1]));
					tfield.setText(""+t1.eLine(t2));
				}
			}
		}
		tfield.requestFocus();
	}


	//Creates a PointCalc Object and sets it visible
	//uses try-catch method to track exception
	//Sets the title as Point Calculator	
	public static void main(String[] args) {
		
		try {
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		} catch (Exception e) {
		}
		PointCalc s = new PointCalc();
		s.setTitle("Point Calculator");
		s.pack();
		s.setVisible(true);
		

	}

}
