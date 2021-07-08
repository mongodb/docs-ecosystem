import MongoSwiftSync

defer {
    cleanupMongoSwift()
}

var opts = MongoClientOptions()
opts.serverAPI = MongoServerAPI(version: .v1)

let client = try MongoClient("mongodb://localhost", options: opts)
let dbNames = try client.listDatabaseNames()
print (dbNames)
