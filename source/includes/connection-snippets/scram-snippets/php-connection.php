<!-- begin scram connection -->
<?php

$client = new MongoDB\Client(
    'mongodb+srv://<username>:<password>@<cluster-address>/test?retryWrites=true&w=majority'
);

$db = $client->test;
?>
<!-- end scram connection -->