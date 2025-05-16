<?php
// Initialize error array
$errors = [];

// Check if the form was submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    // Validate First Name
    if (empty($_POST["firstname"])) {
        $errors[] = "First name is required";
    }
    
    // Validate Last Name
    if (empty($_POST["lastname"])) {
        $errors[] = "Last name is required";
    }
    
    // Validate Address
    if (empty($_POST["address"])) {
        $errors[] = "Address is required";
    }
    
    // Validate Country
    if (empty($_POST["country"])) {
        $errors[] = "Please select a country";
    }
    
    // Validate Skills (at least one skill should be selected)
    if (!isset($_POST["skills"]) || empty($_POST["skills"])) {
        $errors[] = "Please select at least one skill";
    }
    
    // Validate Username
    if (empty($_POST["username"])) {
        $errors[] = "Username is required";
    }
    
    // Validate Password
    if (empty($_POST["password"])) {
        $errors[] = "Password is required";
    }
    
    // Validate Description
    if (empty($_POST["description"])) {
        $errors[] = "Description is required";
    }
    
    // If there are no errors, process the form
    if (empty($errors)) {
        // Display success message and form data
        echo "<!DOCTYPE html>
        <html lang='en'>
        <head>
            <meta charset='UTF-8'>
            <meta name='viewport' content='width=device-width, initial-scale=1.0'>
            <title>Registration Successful</title>
            <style>
                body {
                    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
                    background-color: #f5f5f5;
                    margin: 0;
                    padding: 0;
                    display: flex;
                    justify-content: center;
                    align-items: center;
                    min-height: 100vh;
                }
                .container {
                    background-color: white;
                    border-radius: 10px;
                    box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);
                    padding: 30px;
                    width: 100%;
                    max-width: 600px;
                }
                h2 {
                    text-align: center;
                    color: #4CAF50;
                    margin-bottom: 30px;
                }
                .user-data {
                    margin-bottom: 20px;
                }
                .user-data h3 {
                    color: #333;
                    border-bottom: 1px solid #ddd;
                    padding-bottom: 10px;
                }
                .data-item {
                    margin-bottom: 15px;
                }
                .data-item strong {
                    display: inline-block;
                    width: 120px;
                    color: #555;
                }
                .back-button {
                    display: block;
                    width: 200px;
                    margin: 20px auto 0;
                    padding: 12px;
                    background-color: #4CAF50;
                    color: white;
                    text-align: center;
                    text-decoration: none;
                    border-radius: 5px;
                    font-weight: bold;
                }
                .back-button:hover {
                    background-color: #45a049;
                }
            </style>
        </head>
        <body>
            <div class='container'>
                <h2>Registration Successful!</h2>
                
                <div class='user-data'>
                    <h3>Your Information</h3>
                    
                    <div class='data-item'>
                        <strong>First Name:</strong> " . htmlspecialchars($_POST["firstname"]) . "
                    </div>
                    
                    <div class='data-item'>
                        <strong>Last Name:</strong> " . htmlspecialchars($_POST["lastname"]) . "
                    </div>
                    
                    <div class='data-item'>
                        <strong>Address:</strong> " . htmlspecialchars($_POST["address"]) . "
                    </div>
                    
                    <div class='data-item'>
                        <strong>Country:</strong> " . htmlspecialchars($_POST["country"]) . "
                    </div>
                    
                    <div class='data-item'>
                        <strong>Skills:</strong> " . implode(", ", array_map('htmlspecialchars', $_POST["skills"])) . "
                    </div>
                    
                    <div class='data-item'>
                        <strong>Username:</strong> " . htmlspecialchars($_POST["username"]) . "
                    </div>
                    
                    <div class='data-item'>
                        <strong>Description:</strong> " . htmlspecialchars($_POST["description"]) . "
                    </div>
                </div>
                
                <a href='register.php' class='back-button'>Back to Registration</a>
            </div>
        </body>
        </html>";
        exit;
    }
}

// If there are errors, display them and provide a link back to the form
if (!empty($errors)) {
    echo "<!DOCTYPE html>
    <html lang='en'>
    <head>
        <meta charset='UTF-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <title>Registration Error</title>
        <style>
            body {
                font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
                background-color: #f5f5f5;
                margin: 0;
                padding: 0;
                display: flex;
                justify-content: center;
                align-items: center;
                min-height: 100vh;
            }
            .container {
                background-color: white;
                border-radius: 10px;
                box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);
                padding: 30px;
                width: 100%;
                max-width: 600px;
            }
            h2 {
                text-align: center;
                color: #f44336;
                margin-bottom: 30px;
            }
            .error-list {
                background-color: #ffebee;
                border-left: 4px solid #f44336;
                padding: 15px;
                margin-bottom: 20px;
                border-radius: 4px;
            }
            .error-list ul {
                margin: 10px 0;
                padding-left: 20px;
            }
            .error-list li {
                margin-bottom: 8px;
                color: #d32f2f;
            }
            .back-button {
                display: block;
                width: 200px;
                margin: 20px auto 0;
                padding: 12px;
                background-color: #4CAF50;
                color: white;
                text-align: center;
                text-decoration: none;
                border-radius: 5px;
                font-weight: bold;
            }
            .back-button:hover {
                background-color: #45a049;
            }
        </style>
    </head>
    <body>
        <div class='container'>
            <h2>Registration Error</h2>
            
            <div class='error-list'>
                <p>Please fix the following errors:</p>
                <ul>";
    
    foreach ($errors as $error) {
        echo "<li>" . htmlspecialchars($error) . "</li>";
    }
    
    echo "</ul>
            </div>
            
            <a href='javascript:history.back()' class='back-button'>Back to Form</a>
        </div>
    </body>
    </html>";
    exit;
}
?>