COUNTER=3
while [ $COUNTER -lt 5 ]
do
    curl -X POST http://0.0.0.0:8888/json4 -H 'Content-Type: application/json' -d '{"login":"gaosm","password":"ddddd"}'
done
