import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class AirplaneManagementApp extends JFrame {
    private JTextField airportField;
    private JTextField routeField;
    private JTextField distanceField;
    private JTextArea outputArea;
    private Map<String, Integer> airportMap;
    private int[][] distanceMatrix;
    private int airportCount;
    private JLabel clockLabel;
    private Map<String, Point> airportLocations;
    private JPanel mapPanel;

    public AirplaneManagementApp() {
        setTitle("Airplane Management");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create main panel
        JPanel mainPanel = new JPanel(new BorderLayout());

        // Input panel
        JPanel inputPanel = new JPanel();
        inputPanel.setOpaque(false);
        inputPanel.setLayout(new GridLayout(4, 2, 10, 10));
        inputPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        Font font = new Font("Arial", Font.PLAIN, 20);

        airportField = new JTextField();
        airportField.setFont(font);
        routeField = new JTextField();
        routeField.setFont(font);
        distanceField = new JTextField();
        distanceField.setFont(font);

        inputPanel.add(createLabel("Airport:", font));
        inputPanel.add(airportField);
        inputPanel.add(createLabel("Route (From-To):", font));
        inputPanel.add(routeField);
        inputPanel.add(createLabel("Distance:", font));
        inputPanel.add(distanceField);

        JButton addButton = createButton("Add Route", font, Color.BLUE, Color.BLACK);
        JButton calculateButton = createButton("Calculate Shortest Paths", font, Color.GREEN, Color.BLACK);

        inputPanel.add(addButton);
        inputPanel.add(calculateButton);

        mainPanel.add(inputPanel, BorderLayout.NORTH);

        // Output area
        outputArea = new JTextArea();
        outputArea.setFont(font);
        outputArea.setLineWrap(true);
        outputArea.setWrapStyleWord(true);

        mainPanel.add(new JScrollPane(outputArea), BorderLayout.CENTER);

        // Clock display
        JPanel bottomPanel = new JPanel(new BorderLayout());
        bottomPanel.setOpaque(false);
        clockLabel = new JLabel();
        clockLabel.setFont(font);
        clockLabel.setHorizontalAlignment(SwingConstants.CENTER);
        bottomPanel.add(clockLabel, BorderLayout.CENTER);

        mainPanel.add(bottomPanel, BorderLayout.SOUTH);

        // Map panel
        mapPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawMap(g);
            }
        };
        mapPanel.setPreferredSize(new Dimension(800, 300));
        mapPanel.setBackground(Color.WHITE);

        add(mainPanel, BorderLayout.CENTER);
        add(mapPanel, BorderLayout.SOUTH);

        airportMap = new HashMap<>();
        airportCount = 0;
        distanceMatrix = new int[100][100];
        airportLocations = new HashMap<>();

        // Initialize the distance matrix with large values
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (i == j) {
                    distanceMatrix[i][j] = 0;
                } else {
                    distanceMatrix[i][j] = Integer.MAX_VALUE / 2;
                }
            }
        }

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addRoute();
                mapPanel.repaint();
            }
        });

        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calculateShortestPaths();
                mapPanel.repaint();
            }
        });

        updateClock();
    }

    private JLabel createLabel(String text, Font font) {
        JLabel label = new JLabel(text);
        label.setFont(font);
        label.setForeground(Color.BLACK);
        return label;
    }

    private JButton createButton(String text, Font font, Color bgColor, Color fgColor) {
        JButton button = new JButton(text);
        button.setFont(font);
        button.setBackground(bgColor);
        button.setForeground(fgColor);
        button.setOpaque(true);
        button.setBorderPainted(false);
        return button;
    }

    private void addRoute() {
        String airport = airportField.getText().trim();
        String[] route = routeField.getText().trim().split("-");
        int distance;
        try {
            distance = Integer.parseInt(distanceField.getText().trim());
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid distance. Please enter a number.");
            return;
        }

        if (route.length != 2) {
            JOptionPane.showMessageDialog(this, "Invalid route format. Use 'From-To'.");
            return;
        }

        int fromIndex = getAirportIndex(route[0].trim());
        int toIndex = getAirportIndex(route[1].trim());

        distanceMatrix[fromIndex][toIndex] = distance;
        distanceMatrix[toIndex][fromIndex] = distance;

        outputArea.append("Route added: " + route[0].trim() + " to " + route[1].trim() + " with distance " + distance + "\n");
        updateAirportLocations(route[0].trim(), route[1].trim());
    }

    private int getAirportIndex(String airport) {
        if (!airportMap.containsKey(airport)) {
            airportMap.put(airport, airportCount++);
        }
        return airportMap.get(airport);
    }

    private void calculateShortestPaths() {
        int n = airportCount;
        int[][] dist = new int[n][n];

        // Copy the distance matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = distanceMatrix[i][j];
            }
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        outputArea.append("\nShortest distances between all pairs of airports:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                outputArea.append("From " + getAirportName(i) + " to " + getAirportName(j) + ": " + (dist[i][j] == Integer.MAX_VALUE / 2 ? "INF" : dist[i][j]) + "\n");
            }
        }
    }

    private String getAirportName(int index) {
        for (Map.Entry<String, Integer> entry : airportMap.entrySet()) {
            if (entry.getValue() == index) {
                return entry.getKey();
            }
        }
        return null;
    }

    private void updateAirportLocations(String from, String to) {
        if (!airportLocations.containsKey(from)) {
            airportLocations.put(from, new Point((int) (Math.random() * mapPanel.getWidth()), (int) (Math.random() * mapPanel.getHeight())));
        }
        if (!airportLocations.containsKey(to)) {
            airportLocations.put(to, new Point((int) (Math.random() * mapPanel.getWidth()), (int) (Math.random() * mapPanel.getHeight())));
        }
    }

    private void drawMap(Graphics g) {
        g.setColor(Color.RED);
        for (Map.Entry<String, Point> entry : airportLocations.entrySet()) {
            String airport = entry.getKey();
            Point location = entry.getValue();
            g.fillOval(location.x, location.y, 10, 10);
            g.drawString(airport, location.x + 10, location.y + 10);
        }

        g.setColor(Color.BLUE);
        for (Map.Entry<String, Integer> entry1 : airportMap.entrySet()) {
            String from = entry1.getKey();
            int fromIndex = entry1.getValue();
            for (Map.Entry<String, Integer> entry2 : airportMap.entrySet()) {
                String to = entry2.getKey();
                int toIndex = entry2.getValue();
                if (distanceMatrix[fromIndex][toIndex] != Integer.MAX_VALUE / 2) {
                    Point fromLocation = airportLocations.get(from);
                    Point toLocation = airportLocations.get(to);
                    g.drawLine(fromLocation.x, fromLocation.y, toLocation.x, toLocation.y);
                }
            }
        }
    }

    private void updateClock() {
        Timer timer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
                clockLabel.setText(sdf.format(new Date()));
            }
        });
        timer.start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new AirplaneManagementApp().setVisible(true);
            }
        });
    }
}
