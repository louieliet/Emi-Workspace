CREATE TABLE players (
    player_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    birth_date DATE,
    position VARCHAR(20),
    team VARCHAR(50),
    goals INT,
    yellow_cards INT,
    red_cards INT,
    injured BOOL
);

-- Creation of the fouls table
CREATE TABLE fouls (
    foul_id INT PRIMARY KEY,
    player_id INT,
    type VARCHAR(20),
    date_time DATETIME,
    FOREIGN KEY (player_id) REFERENCES players(player_id)
);

-- Creation of the match statistics table
CREATE TABLE match_statistics (
    match_id INT PRIMARY KEY,
    date DATE,
    home_team VARCHAR(50),
    away_team VARCHAR(50),
    home_goals INT,
    away_goals INT,
    home_possession INT,
    away_possession INT,
    home_corners INT,
    away_corners INT
);

-- Adding records to the players table
INSERT INTO players (player_id, first_name, last_name, birth_date, position, team, goals, yellow_cards, red_cards, injured) VALUES
(1, 'Lionel', 'Messi', '1987-06-24', 'Forward', 'Paris Saint-Germain', 2, 0, 0, false),
(2, 'Cristiano', 'Ronaldo', '1985-02-05', 'Forward', 'Manchester United', 3, 1, 0, false),
(3, 'Sergio', 'Ramos', '1986-03-30', 'Defender', 'Paris Saint-Germain', 0, 2, 1, true),
(4, 'Neymar', 'Jr.', '1992-02-05', 'Forward', 'Paris Saint-Germain', 1, 1, 0, false),
(5, 'Kylian', 'Mbappé', '1998-12-20', 'Forward', 'Paris Saint-Germain', 4, 0, 0, false);

-- Adding records to the fouls table
INSERT INTO fouls (foul_id, player_id, type, date_time) VALUES
(1, 1, 'Foul', '2021-10-10 14:30:00'),
(2, 2, 'Foul', '2021-10-10 14:45:00'),
(3, 3, 'Yellow card', '2021-10-10 15:00:00'),
(4, 4, 'Foul', '2021-10-10 15:15:00'),
(5, 5, 'Goal', '2021-10-10 15:30:00');

-- Adding records to the match statistics table
INSERT INTO match_statistics (match_id, date, home_team, away_team, home_goals, away_goals, home_possession, away_possession, home_corners, away_corners) VALUES
(1, '2021-10-10', 'Real Madrid', 'Barcelona', 2, 1, 60, 40, 5, 3),
(2, '2021-10-17', 'Manchester United', 'Liverpool', 1, 1, 45, 55, 2, 4),
(3, '2021-10-24', 'Paris Saint-Germain', 'Marseille', 3, 0, 70, 30, 7, 1),
(4, '2021-10-31', 'Bayern Munich', 'Borussia Dortmund', 2, 2, 50, 50, 3, 3),
(5, '2021-11-07', 'Juventus', 'Inter Milan', 0, 1, 35, 65, 1, 5);


-- Selecting everything from the three tables
SELECT * FROM players;
SELECT * FROM fouls;
SELECT * FROM match_statistics;

-- Extracting the sum of goals from the players table
SELECT SUM(goals) FROM players;

-- Sorting in ascending order by birth date in the players table
SELECT * FROM players ORDER BY birth_date ASC;

-- Query with filter by team in the players table
SELECT * FROM players WHERE team = 'Real Madrid';

-- Inserting an extra record in the fouls table
INSERT INTO fouls (foul_id, player_id, type, date_time) VALUES (6, 3, 'Offside', '2021-10-10 15:30:00');

-- Deletion of records from the players table
DELETE FROM players WHERE team = 'Real Madrid';

-- Counting fouls per player
SELECT players.first_name, players.last_name, COUNT(fouls.foul_id) AS total_fouls
FROM players
LEFT JOIN fouls ON players.player_id = fouls.player_id
GROUP BY players.player_id;

-- Getting the data type of a field
SELECT type FROM sqlite_master WHERE name = 'players' AND sql LIKE '%goals%';