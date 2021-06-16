.. note::

    If you want to connect to a database server running locally on its
    default port, change the Atlas connection string to
    ``"mongodb://localhost"``.

    If you have a specific port you want to connect to, change the Atlas
    connection string to ``"mongodb://localhost:<port_number>"``. For
    example, if you want to connect to port ``27017``, change the Atlas 
    connection string to ``"mongodb://localhost:27017"``.

    Your mongod instance must be running to successfully connect to your
    database server. 
    
    For information on how to start your mongod instance, see the
    :manual:`Manage mongod Processes
    </manage-mongodb-processes/#start-mongod-processes>` Server Manual Entry.
