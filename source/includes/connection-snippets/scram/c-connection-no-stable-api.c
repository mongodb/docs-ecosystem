#include <mongoc/mongoc.h>

int
main (int argc, char *argv[])
{
   mongoc_database_t *database;
   mongoc_client_t *client;

   mongoc_init ();

   // Replace the uri string with your MongoDB deployment's connection string.
   client = mongoc_client_new(
      "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
   );
   database = mongoc_client_get_database (client, "test");

   mongoc_database_destroy (database);
   mongoc_client_destroy (client);

   mongoc_cleanup ();

   return 0;
}
