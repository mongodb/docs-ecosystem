<?php
/* Begin scram connection */
$client = new MongoDB\Client(
    'mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority'
);

$collection = $client->testDB->testCol;
$docCount = $collection->count([]);
print($docCount);
/* End scram connection */