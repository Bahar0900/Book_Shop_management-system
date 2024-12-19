<!DOCTYPE html>
<html>
<head>
    <title>README - Sagor's Book Shop</title>
</head>
<body>
    <h1>Sagor's Book Shop</h1>
    <p>A simple C++ application to manage books in a bookshop. It provides functionalities for both customers and administrators to interact with the system effectively.</p>

    <h2>Features</h2>
    <ul>
        <li>Admin Features:
            <ul>
                <li>Add new books</li>
                <li>Update book details</li>
                <li>Delete books</li>
            </ul>
        </li>
        <li>Customer Features:
            <ul>
                <li>Search for books</li>
                <li>View all available books</li>
                <li>Purchase books</li>
            </ul>
        </li>
    </ul>

    <h2>Technologies Used</h2>
    <ul>
        <li>C++</li>
        <li>File Handling</li>
        <li>Object-Oriented Programming</li>
    </ul>

    <h2>Setup and Usage</h2>
    <ol>
        <li>Clone or download the project code to your local machine.</li>
        <li>Open the project folder in a C++ IDE or a terminal.</li>
        <li>Ensure you have a C++ compiler (e.g., g++).</li>
        <li>Compile the code using the following command in your terminal:
            <pre>g++ -o BookShop main.cpp</pre>
        </li>
        <li>Run the executable:
            <pre>./BookShop</pre>
        </li>
    </ol>

    <h3>Admin Log In</h3>
    <p>Admins can log in with their credentials stored in the <code>Admin_input.txt</code> file.</p>

    <h3>Customer Log In and Sign Up</h3>
    <p>Customers can log in or sign up. Credentials are stored in the <code>Customer_input.txt</code> file.</p>

    <h2>File Structure</h2>
    <ul>
        <li><code>main.cpp</code>: Contains the source code for the application.</li>
        <li><code>Information.txt</code>: Stores book details.</li>
        <li><code>Admin_input.txt</code>: Stores admin credentials.</li>
        <li><code>Customer_input.txt</code>: Stores customer credentials.</li>
    </ul>

    <h2>License</h2>
    <p>This project is licensed under the MIT License.</p>
</body>
</html>
