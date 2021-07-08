import MongoSwift
import NIO

let elg = MultiThreadedEventLoopGroup(numberOfThreads: 4)

var opts = MongoClientOptions()
opts.serverAPI = MongoServerAPI(version: .v1)

let client = try MongoClient(
    "mongodb://localhost:27017",
    using: elg,
    options:opts
)
