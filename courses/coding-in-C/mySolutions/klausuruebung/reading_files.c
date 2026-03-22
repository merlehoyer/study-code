#include <stdio.h>
#include <stdlib.h>

typedef struct SensorData{
    float time;
    double probability;
} SensorData;

typedef struct Sensor{
    int id;
    double threshold;
    SensorData data[3000];
    int object_detection[3000];
} Sensor;

void reading_files(Sensor *p_act_Sensor, char *filename){

    FILE *fptr= fopen(("%s", filename),"r");
    if(fptr ==NULL){
        return;
    }
    
    int i = 0;
    
    while(fscanf(fptr,"%f %lf", &p_act_Sensor->data[i].time, &p_act_Sensor->data[i].probability)==2){
        i++;
    }

    fclose(fptr);
    return;
}

void creating_detection_signal(Sensor *act_sensor, int sensor_length){

    for( int i =0; i <sensor_length; i++){
        if(act_sensor->data[i].probability > act_sensor->threshold){
            act_sensor->object_detection[i] = 1; 
        } else{
            act_sensor->object_detection[i] = 0;
        }
    }

    return;
}

void determining_intervals_start(Sensor *act_sensor, int sensor_length, float *start_times){

    //float start_times[100]= {0};
    int iterator =0;
    for(int i=0; i<sensor_length; i++){
        if(act_sensor->object_detection[i]==0 && act_sensor->object_detection[i+1]==1){
            start_times[iterator]= (i+1)*0.02;
            iterator++;
        }
    }

    return;
}

void determining_intervals_end(Sensor *act_sensor, int sensor_length, float *end_times){

    //float end_times[100]= {0};
    int iterator =0;
    for(int i=0; i<sensor_length; i++){
        if(act_sensor->object_detection[i]==1 && act_sensor->object_detection[i+1]==0){
            end_times[iterator]= (i)*0.02;
            iterator++;
        }
    }

    return;
}

int main(){

    Sensor sensor1;
    Sensor sensor2;

    sensor1.threshold= 0.8;

    reading_files(&sensor1, "../reading_files/sensor1.txt");

    for(int i =0; i<10; i++){
        printf("%.2f %.2lf\n", sensor1.data[i].time, sensor1.data[i].probability);
    }

    creating_detection_signal(&sensor1, 3000);

    for(int i =0; i<10; i++){
        printf("%d\n", sensor1.object_detection[i]);
    }

    float start[100]; 
    determining_intervals_start(&sensor1, 3000, start );
    float end[100];
    determining_intervals_end(&sensor1, 3000, end);

    for(int i =0; i<10; i++){
        printf("start times:%.2fs / end time: %.2f s \n", *(start+i), *(end+i));
    }

    return 0; 
}