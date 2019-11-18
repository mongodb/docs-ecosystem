// begin x509 connection
#include <mongoc/mongoc.h>

int
main (int argc, char *argv[])
{
   mongoc_database_t *database;
   mongoc_client_t *client;

   mongoc_init ();

   const mongoc_ssl_opt_t *ssl_default = mongoc_ssl_opt_get_default ();
   mongoc_ssl_opt_t ssl_opts = { 0 };

   memcpy(&ssl_opts, ssl_default, sizeof ssl_opts);

   ssl_opts.pem_file = "/etc/certs/mongodb/client.pem";
   ssl_opts.ca_file = "/etc/certs/mongodb/ca.pem";
   ssl_opts.weak_cert_validation = false;
   ssl_opts.allow_invalid_hostname = false;

   client = mongoc_client_new ("mongodb+srv://<your-x509-client-subject>@<cluster-url>/?authMechanism=MONGODB-X509");
   mongoc_client_set_ssl_opts (client, &ssl_opts);
   database = mongoc_client_get_database (client, "test");

   mongoc_client_destroy (client);
   mongoc_database_destroy (database);
   mongoc_cleanup ();

   return EXIT_SUCCESS;
}
// end x509 connection 