<?php
    include 'db.php';

    $query = "SELECT * FROM users ORDER BY u_id";
    $run = $con->query($query);

    $fromName = $_POST['fromName'];
    $from_u_id = $_POST['from_u_id'];

echo "<h3>Other persons</h3>";

echo "<div style=\"margin:0 auto;display: inline-block;\" >";
    while($row = $run->fetch_array()):
?>

<?php
    if( $row['name'] != $fromName ):
?>

    <?php
        $person_id = $row['u_id'];
        $name = $row['name'];

    echo "<label class=\"container\">$name \n";
    echo "  <input type=\"radio\" name=\"otherPerson\"  value=\"$person_id \" >\n";
    echo "  <span class=\"checkmark\"></span>\n";
    echo "</label>\n";
    ?>

   <?php
    endif;
    ?>
    <?php
    endwhile;
    ?>

</div>

<div > <!-- style="background-color: red" -->
    <p>Enter the amount of credits to transfer:</p>
    <input type="text" size="40px" id="amount" name="amount"/>

<?php
echo "<input type=\"submit\" id=\"send\" name=\"submit\" value=\"Send!\" onclick=\"transaction($from_u_id)\" />";
?>

</div>


