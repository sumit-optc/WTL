<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "WTL";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully</br>";

$name = $email = $phno = $addr = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = $_REQUEST["fname"];
  $email = $_REQUEST["username"];
  $phno = $_REQUEST["phno"];
  $addr = $_REQUEST["address"];

  $sql = " INSERT INTO Test VALUES('$name', '$email', '$phno', '$addr' )";
  if(mysqli_query($conn, $sql)){
      echo '<h3> entry successfull, click <a 
      href="http://localhost/phpmyadmin/index.php?route=/sql&server=1&db=wtl&table=test&pos=0" target="_blank"> 
      here </a>to see table</h3>';

      echo nl2br("\nName: $name\nEmail: $email\nPhone Number: $phno\nAddress: $addr");
  } 
  else{
      echo "Error: $sql". mysqli_error($conn);
  }
}
mysqli_close($conn);

?>