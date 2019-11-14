<!-- Begin x509 connection -->
<?php

$database = 'test';
$subject = "mongodb://<your_subject>"; // mongodb://CN=<host>,OU=TestClientCertificateOrgUnit,O=TestClientCertificateOrg,L=TestClientCertificateLocality,ST=TestClientCertificateState,C=US
$manager = new MongoDB\Driver\Manager(
  $subject + "@localmongo1/?ssl=true&authMechanism=MONGODB-X509",
  [],
  [
    "pem_file" => "/Users/<user>/dev/drivers/certs/v3/test-client.pem",
    "ca_file" => "/Users/<user>/dev/drivers/certs/v3/test-ca.pem",
  ]
);
?>

<!-- End x509 connection -->