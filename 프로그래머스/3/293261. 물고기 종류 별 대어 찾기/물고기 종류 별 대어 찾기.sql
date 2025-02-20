WITH ranked_fish AS (
    SELECT ID, FISH_TYPE, LENGTH, 
           ROW_NUMBER() OVER (PARTITION BY FISH_TYPE ORDER BY LENGTH DESC, ID ASC) AS rn
    FROM FISH_INFO
)
SELECT r.ID, f.fish_name , r.LENGTH
FROM ranked_fish r join fish_name_info f on r.fish_type = f.fish_type 
WHERE rn = 1
ORDER BY ID;
