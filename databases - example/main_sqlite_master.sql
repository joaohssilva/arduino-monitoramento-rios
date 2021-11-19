create table sqlite_master
(
    type     text,
    name     text,
    tbl_name text,
    rootpage int,
    sql      text
);

INSERT INTO sqlite_master (type, name, tbl_name, rootpage, sql) VALUES ('table', 'data', 'data', 2, 'CREATE TABLE "data"
(
	pH TEXT,
	temperatura TEXT,
	turbidez TEXT
)');