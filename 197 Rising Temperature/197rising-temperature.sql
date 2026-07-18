SELECT w1.id
 FROM WEATHER w1 JOIN weather w2 
 ON DATEDIFF(W1.recordDate,w2.recordDate)=1
 where w1.temperature>w2.temperature;

