#include <stdio.h>

struct SensorData{
    float time;
    double probability; // value = 0-1

};

struct sensor{
    int id;
    double threshold;
    struct SensorData data[3002];
    int object_detection[3002]; // 1 for signal> threshold / 0 otherwise
    
    int start_times[100];
    int end_times[100];
};

int getting_sensorData(struct sensor *p_sensorx, char file_name[50]){

    FILE *output = fopen(("%s",file_name), "r");
    if(output==NULL){
        printf("Error opening sensordata file");
        return 1;
    }

    float var[3];

    int i=0; // for iterating through data array
    while(fscanf(output, "%f %lf", &p_sensorx->data[i].time, &p_sensorx->data[i].probability)==2){
        //printf("%f\n", p_sensorx->data->time);
        //printf("%lf", p_sensorx->data->probability);
        i++; 
    }

    /*
    for(int j=0; j<10; j++){
        printf("%.2f %.2lf\n",p_sensorx->data[j].time, p_sensorx->data[j].probability);
    }
    
    fscanf(output, "%f %f", var, var+1);
    printf("%.2f", var);
    printf("%.2f", *(var+1));
    */
    
    if(fclose(output)!=0){
        printf("Error: problems closing file");
        return 1;
    }


    return 0;

};

void detecting_sensor(struct sensor *p_sensorx){

    int number_read_values = 3000;
    
    //compares set threshold value with variable probability value and saves binary signal in array
    for(int i=0; i< number_read_values; i++){

        if(p_sensorx->data[i].probability > p_sensorx->threshold){
            p_sensorx->object_detection[i]=1;
        } else{
            p_sensorx->object_detection[i]=0;
        }
    }
    
    /*
    for (int i =950; i <1010; i++){
    printf("%d\n", p_sensorx->object_detection[i]);

    }
    */

    return; 
};


void determining_intervals(struct sensor *p_sensorx){

    //everytime signal changes from 0 to 1 the start array saves the step counter value, the same for the end array and its switch from 1 to 0

    int number_read_values = 3000;
    int j=0; //indikator for start times array
    int k=0; //indikator for end times array

    for(int i=0; i< number_read_values; i++){
        
        

        if((p_sensorx->object_detection[i]==0)&& (p_sensorx->object_detection[i+1]==1)){
            p_sensorx->start_times[j]=i+1;
            j++;
        } else if((p_sensorx->object_detection[i]==1)&&(p_sensorx->object_detection[i+1]==0)){
            p_sensorx->end_times[k]=i;
            k++;
        }

    }

    //for finding end of array
    p_sensorx->start_times[j]= 12; 
    p_sensorx->end_times[k]=12;
   
    return; 
};

void visual_output(struct sensor *p_sensor1, struct sensor *p_sensor2){

    int fused_signal_s[100]; 
    int fused_signal_e[100];

    printf("---- Object Detection Results ----\n");
    printf("Sensor 1 detections: ");
    //output sensor 1 times
    int i=0;
    while((p_sensor1->start_times[i]!=12)&&(p_sensor1->end_times[i]!=12)){
        printf("Start: %.2f s End: %.2f s ",p_sensor1->start_times[i]*0.02, p_sensor1->end_times[i]*0.02);
        i++;
    }

    printf("\nSensor 2 detections: ");
    //output sensor 2 times
    i=0;
    while((p_sensor2->start_times[i]!=12)&&(p_sensor2->end_times[i]!=12)){
        printf("Start: %.2f s End: %.2f s ",p_sensor2->start_times[i]*0.02, p_sensor2->end_times[i]*0.02);
        i++;
    }

    printf("\nFused signals: ");
    int iterator=0;
    
    while((p_sensor1->end_times[iterator]!=12)&&(p_sensor2->end_times[iterator]!=12)){
        
        //determining start times 

        if(p_sensor1->start_times[iterator] > p_sensor2->start_times[iterator]){
            fused_signal_s[iterator]=p_sensor1->start_times[iterator];
        } else{
            fused_signal_s[iterator]=p_sensor2->start_times[iterator];
        }

        //determining end times 
        
        if(p_sensor1->end_times[iterator] > p_sensor2->end_times[iterator]){
            fused_signal_e[iterator]= p_sensor2->end_times[iterator];
        } else {
            fused_signal_e[iterator]= p_sensor1->end_times[iterator];
        }

        iterator++;
    }

    for(int j=0; j<iterator; j++){
        printf(" Start: %.2f s End: %.2f s", fused_signal_s[j]*0.02, fused_signal_e[j]*0.02);
    }

    return;
}


int main (){

    struct sensor sensor1;
    struct sensor sensor2;

    sensor1.threshold = 0.8;
    sensor2.threshold = 0.7;

    struct sensor *p_sensor1 = &sensor1;
    struct sensor *p_sensor2 = &sensor2;

    if(getting_sensorData(p_sensor1, "sensor1.txt" )!=0){
        printf("ERROR");
        return 1;
    }
    
    if(getting_sensorData(p_sensor2, "sensor2.txt")!=0){
        printf("ERROR");
        return 1;
    }

    detecting_sensor(p_sensor1);
    detecting_sensor(p_sensor2);


    determining_intervals(p_sensor1);
    determining_intervals(p_sensor2);

    visual_output(p_sensor1, p_sensor2);


    return 0;
}

//Frage: warum funktioniert mit fused_signal_s[iterator]=p_sensor2->start_times[iterator]*0.02 nicht aber ohne *0.02 schon?