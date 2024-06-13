
CREATE TABLE IF NOT EXISTS albums (
	id SERIAL PRIMARY KEY,
	name VARCHAR(42) NOT NULL,
	year_of_issue INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS performers (
	id SERIAL PRIMARY KEY,
	name VARCHAR(42) NOT NULL
);

CREATE TABLE IF NOT EXISTS genres (
	id SERIAL PRIMARY KEY,
	name VARCHAR(42) NOT NULL
);

CREATE TABLE IF NOT EXISTS tracks (
	id SERIAL PRIMARY KEY,
	name VARCHAR(42) NOT NULL,
	duration INTEGER NOT NULL,
	album_id INTEGER NOT NULL REFERENCES albums(id)
);

CREATE TABLE IF NOT EXISTS collections (
	id SERIAL PRIMARY KEY,
	name VARCHAR(42) NOT NULL,
	year_of_issue INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS albums_performers (
	album_id INTEGER REFERENCES albums(id),
	performer_id INTEGER REFERENCES performers(id),
	CONSTRAINT pk1 PRIMARY KEY (album_id, performer_id)
);

CREATE TABLE IF NOT EXISTS genres_performers (
	genre_id INTEGER REFERENCES genres(id),
	performer_id INTEGER REFERENCES performers(id),
	CONSTRAINT pk2 PRIMARY KEY (genre_id, performer_id)
);

CREATE TABLE IF NOT EXISTS collections_tracks (
	collection_id INTEGER REFERENCES collections(id),
	track_id INTEGER REFERENCES tracks(id),
	CONSTRAINT pk3 PRIMARY KEY (collection_id, track_id)
);