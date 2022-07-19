BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "client" (
	"id"	INTEGER NOT NULL,
	"name"	TEXT NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT)
);
INSERT INTO "client" VALUES (1,'ivan');
INSERT INTO "client" VALUES (2,'alex');
INSERT INTO "client" VALUES (3,'bors');
INSERT INTO "client" VALUES (4,'coco');
INSERT INTO "client" VALUES (5,'xoxo');
INSERT INTO "client" VALUES (6,'rara');
COMMIT;
