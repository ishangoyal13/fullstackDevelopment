<?php
    include 'db.php';

$from_u_id = $_POST['from_u_id'];

$to_u_id = $_POST['to_u_id'];

$amount = $_POST['amount'];

# debit
$query_debit = "UPDATE users
SET credits = credits - $amount
WHERE u_id = $from_u_id
";

$run = $con->query($query_debit);

if($run){
    // echo "<b>query_debit is successfullt</b><br /><b>$query_debit</b>";
}else{
    // error
}


# credit
$query_credit = "UPDATE users
SET credits = credits + $amount
WHERE u_id = $to_u_id
";

$run = $con->query($query_credit);

if($run){
    // echo "<b>query_credit is successfullt</b><br /><b>$query_credit</b>";
}else{
    // error
}
// ---------------------------------------------
echo "<h3>Transaction has been successful !</h3>";
echo "<h4>You can go Home and verify the credits !</h4>";

# "" update transfer Table ""

$query_transfer_table = "
INSERT INTO transfer (from_u_id, to_u_id, credits) VALUES ($from_u_id, $to_u_id, $amount);
";

$run = $con->query($query_transfer_table);
if($run){
    // echo "<b>query_transfer_table is successfull</b>";
}else{
    // error
}

?>
