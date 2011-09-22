#include <stdio.h>  
#define SEC_PR_HOUR 3600
#define SEC_PR_MIN 60
int main(void)
{
    /* variables are pre-definered */
    int hours, minutes, seconds, input_seconds;
    
    /* Prompt for seconds */
    printf("Input seconds: ");
    scanf("%d", &input_seconds);
    
    /* Calculate hours, seconds and minutes */
    hours   =   input_seconds/SEC_PR_HOUR;
    hours   =   hours%SEC_PR_MIN;
    
    minutes =   input_seconds/SEC_PR_MIN;
    minutes =   minutes%SEC_PR_MIN;
    
    seconds =   input_seconds%SEC_PR_MIN;
    
    /* Write result if non-zero */
    if(hours != 0){
        printf("%d %s", hours, hours == 1 ? "time " : "timer ");            /* Write 'time' if hours==1 and 'timer' if hours!=1 */
    }
    if(minutes != 0){
        printf("%d %s", minutes, minutes == 1 ? "minut " : "minutter ");    /* Write 'minut' if minutes==1 and 'minutter' if minutes!=1 */
    }
    if(seconds != 0){
        printf("%d %s", seconds, seconds == 1 ? "sekund" : "sekunder");     /* Write 'sekund' if seconds==1 and 'sekunder' if seconds!=1 */
    }
    return 0;
}
