To connect to a database running locally on its default port, change the
connection string to ``"mongodb://localhost"``. 

To connect to a specific port, change the connection string to
``"mongodb://localhost:<port_number>"``. 

For example, to connect to port ``27017``, change the connection string
to ``"mongodb://localhost:27017"``. 

Your ``mongod`` instance must be running to successfully connect to your
database. For information on how to start your ``mongod`` instance,
see the :manual:`Manage mongod Processes
</tutorial/manage-mongodb-processes/#start-mongod-processes>` Server Manual Entry.
