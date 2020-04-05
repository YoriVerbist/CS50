SELECT name FROM people
JOIN stars ON stars.person_id = people.id
WHERE stars.movie_id in 
	(SELECT movie_id FROM stars WHERE stars.person_id = 
		(SELECT id from people WHERE name = 'Kevin Bacon'))
AND NOT name = 'Kevin Bacon'
GROUP BY name;