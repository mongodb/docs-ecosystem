// begin x509 connection
#include <mongoc/mongoc.h>

int
main (int argc, char *argv[])
{
   mongoc_client_t *client;
   mongoc_database_t *database;
   mongoc_collection_t *collection;
   bson_t *command, reply, *insert;
   bson_error_t error;
   char *str;
   bool retval;

   /*
    * Required to initialize libmongoc's internals
    */
   mongoc_init ();

   const mongoc_ssl_opt_t *ssl_default = mongoc_ssl_opt_get_default ();
   mongoc_ssl_opt_t ssl_opts = { 0 };

   memcpy (&ssl_opts, ssl_default, sizeof ssl_opts);

   ssl_opts.pem_file = "/client.pem";
   ssl_opts.ca_file = "/ca.pem";
   ssl_opts.weak_cert_validation = false;
   ssl_opts.allow_invalid_hostname = false;
   
   char subject[] = "mongodb://<your_subject>"; // mongodb://CN%3DChris%2COU%3DTestClientCertificateOrgUnit%2CO%3DEducationClientCertificate%2CL%3DTestClientCertificateLocality%2CST%3DTestClientCertificateState%2CC%3DUS
   char uri[] = strcat(subject,"@localmongo1/?authMechanism=MONGODB-X509")
   client = mongoc_client_new (uri);
   mongoc_client_set_ssl_opts (client, &ssl_opts);

   /*
    * Register the application name so we can track it in the profile logs
    * on the server. This can also be done from the URI (see other examples).
    */
   mongoc_client_set_appname (client, "mongoc-example");

   /*
    * Get a handle on the database "db_name" and collection "coll_name"
    */
   database = mongoc_client_get_database (client, "test");

   mongoc_client_destroy (client);
   mongoc_cleanup ();

   return EXIT_SUCCESS;
}
// end x509 connection