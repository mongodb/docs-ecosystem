// begin x509 connection
#include <mongoc/mongoc.h>

int
main (int argc, char *argv[])
{
   mongoc_collection_t *collection;
   mongoc_client_t *client;
   int64_t count;

   mongoc_init ();

   const mongoc_ssl_opt_t *ssl_default = mongoc_ssl_opt_get_default ();
   mongoc_ssl_opt_t ssl_opts = { 0 };

   memcpy(&ssl_opts, ssl_default, sizeof ssl_opts);

   ssl_opts.pem_file = "/etc/certs/mongodb/client.pem";

   client = mongoc_client_new ("mongodb+srv://<cluster-url>/test?authSource=$external&retryWrites=true&w=majority&authMechanism=MONGODB-X509");
   mongoc_client_set_ssl_opts (client, &ssl_opts);

   collection = mongoc_client_get_collection (client, "testDB", "testCol");
   count = mongoc_collection_count_documents(collection, bson_new (), NULL, NULL, NULL, NULL);
   printf ("%" PRId64 " documents counted.\n", count);

   mongoc_client_destroy (client);
   mongoc_cleanup ();

   return EXIT_SUCCESS;
}
// end x509 connection