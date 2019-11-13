<!-- Begin x509 connection -->
<?php

$database = 'test';
$manager = new MongoDB\Driver\Manager(
  "mongodb://CN=<host>,OU=TestClientCertificateOrgUnit,O=TestClientCertificateOrg,L=TestClientCertificateLocality,ST=TestClientCertificateState,C=US@localmongo1/?ssl=true&authMechanism=MONGODB-X509",
  [],
  [
    "pem_file" => "/Users/<user>/dev/drivers/certs/v3/test-client.pem",
    "ca_file" => "/Users/<user>/dev/drivers/certs/v3/test-ca.pem",
  ]
);
$bulk = new MongoDB\Driver\BulkWrite;
$bulk->insert(['phptest' => 'ok']);
$manager->executeBulkWrite('test.stuff', $bulk);
?>

<!-- End x509 connection -->