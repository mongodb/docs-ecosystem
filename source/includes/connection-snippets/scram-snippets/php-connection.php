<?php
/* Begin x509 connection */
$client = new MongoDB\Client(
    'mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority'
);

$db = $client->test;
/* End x509 connection */