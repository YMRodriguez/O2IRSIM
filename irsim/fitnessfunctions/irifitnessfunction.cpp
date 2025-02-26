#include "irifitnessfunction.h"
#include "collisionmanager.h"

#define SEARCH 	0
#define DEPOSIT 1
/******************************************************************************/
/******************************************************************************/

CIriFitnessFunction::CIriFitnessFunction(const char* pch_name, 
                                                                 CSimulator* pc_simulator, 
                                                                 unsigned int un_collisions_allowed_per_epuck)
    :
    CFitnessFunction(pch_name, pc_simulator)
{

	/* Check number of robots */
	m_pcSimulator = pc_simulator;
	TEpuckVector* pvecEpucks=m_pcSimulator->GetEpucks();
	
	if ( pvecEpucks->size() == 0 )
	{
		printf("No Robot, so fitness function can not be computed.\n Exiting...\n");
		fflush(stdout);
		exit(0);
	}
	else if  (pvecEpucks->size()>1)
	{
		printf("More than 1 robot, and fitness is not prepared for it.\n Exiting...\n");
	}
    
	m_pcEpuck=(*pvecEpucks)[0];

	m_unNumberOfSteps = 0;
	m_fComputedFitness = 0.0;
	m_unState = SEARCH;

	
	m_unCollisionsNumber= 0;		
	m_unGreyFlag = 0;
	m_unGreyCounter = 0;
	
}

/******************************************************************************/
/******************************************************************************/

CIriFitnessFunction::~CIriFitnessFunction(){
}
/******************************************************************************/
/******************************************************************************/

double CIriFitnessFunction::GetFitness()
{    

	/* If you need to check the collisions of the robot, here are the total number of 
	 * collisions done by the robot in the simulations */
	int coll = (CCollisionManager::GetInstance()->GetTotalNumberOfCollisions());

	/* Get the fitness divided by the number of steps */
 	 double fit = ( m_fComputedFitness / (double) m_unNumberOfSteps ) * (1 - ((double) (fmin(m_unCollisionsNumber,30.0)/30.0))) * ( (double) (fmin(m_unGreyCounter, 5.0)/ 5.0 ));
 	 

	/* If fitness less than 0, put it to 0 */
	if ( fit < 0.0 ) fit = 0.0;
	if ( fit > 1.0 ) fit = 1.0;


	return fit;
}

/******************************************************************************/
/******************************************************************************/
void CIriFitnessFunction::SimulationStep(unsigned int n_simulation_step, double f_time, double f_step_interval)
{
	/* See Evolutionary Robotics Book */
	/* This is the function to be implemented */
	/* f = V * ( 1 - sqrt(Delta(v)) ) * (1 - i)
	 * V relates to the maximum speed
	 * Delta(v) relates to the movement on the same direction
	 * i relates to the maximum sensor value
	 */

	/* Get actual SPEED of the left and right wheel */
	double leftSpeed = 0.0;
	double rightSpeed = 0.0;
	m_pcEpuck->GetWheelSpeed(&leftSpeed,&rightSpeed);
	leftSpeed = 0.5 + ( leftSpeed / ( 2.0 *  m_pcEpuck->GetMaxWheelSpeed()) );
	rightSpeed = 0.5 + ( rightSpeed / ( 2.0 *  m_pcEpuck->GetMaxWheelSpeed()) );

	/* Eval maximum speed partial fitness */
	double maxSpeedEval = (fabs(leftSpeed - 0.5) + fabs(rightSpeed - 0.5));

	/* Eval same direction partial fitness */
	double sameDirectionEval = 1 - sqrt(fabs(leftSpeed - rightSpeed));
	
	/* Eval SENSORS */

	/* Where the Max PROXIMITY sensor will be stored*/
	double maxProxSensorEval 		= 0.0;
	/* Where the Max LIGHT sensor will be stored*/
	double maxLightSensorEval 	= 0.0;
	/* Where the Max BLUE LIGHT sensor will be stored*/
	double maxBlueLightSensorEval 	= 0.0;
	/* Where the Max RED LIGHT sensor will be stored*/
	double maxRedLightSensorEval 	= 0.0;
	/* Where the Max CONTACT sensor will be stored*/
	double maxContactSensorEval = 0.0;

	/* Where the GROUND MEMORY will be stored */
	double* groundMemory;
	/* Where the GROUND will be stored */
	double* ground;
	/* whre the RED BATTERY will be sotored */
	double *redBattery;

	double blueLightS0=0;
	double blueLightS2=0;
	double blueLightS5=0;
	double blueLightS7=0;
	double lightS0=0;
	double lightS2=0;
	double lightS5=0;
	double lightS7=0;
	double redLightS0=0;
	double redLightS2=0;
	double redLightS5=0;
    	double redLightS7=0;

	/* Auxiluar variables */
	unsigned int unThisSensorsNumberOfInputs; 
	double* pfThisSensorInputs; 
	
	/* Go in all the sensors */
	TSensorVector vecSensors = m_pcEpuck->GetSensors();
	for (TSensorIterator i = vecSensors.begin(); i != vecSensors.end(); i++)
	{
		/* Check type of sensor */
		switch ( (*i)->GetType() )
		{
			/* If sensor is PROXIMITY */
			case SENSOR_PROXIMITY:
				/* Get the number of inputs */
				unThisSensorsNumberOfInputs = (*i)->GetNumberOfInputs();
				/* Get the actual values */
				pfThisSensorInputs = (*i)->GetComputedSensorReadings();

				/* For every input */
				for (int j = 0; j < unThisSensorsNumberOfInputs; j++)
				{
					/* If reading bigger than maximum */
					if ( pfThisSensorInputs[j] > maxProxSensorEval )
					{	
						/* Store maximum value */
						maxProxSensorEval = pfThisSensorInputs[j];
					}
				}
				break;

			/* If sensor is GROUND_MEMORY */
			case SENSOR_GROUND_MEMORY:
				/* Get the actual value */
				groundMemory = (*i)->GetComputedSensorReadings();
				break;
	
			/* If sensor is GROUND */
			case SENSOR_GROUND:
				/* Get actual values */
				ground = (*i)->GetComputedSensorReadings();
				break;	
			/* If sensor is LIGHT */
			case SENSOR_REAL_LIGHT:
				/* Get number of inputs */
				unThisSensorsNumberOfInputs = (*i)->GetNumberOfInputs();
				/* Get the actual values */
				pfThisSensorInputs = (*i)->GetComputedSensorReadings();

				/* For every input */
				for (int j = 0; j < unThisSensorsNumberOfInputs; j++)
				{
					/* If reading bigger than maximum */
					if ( pfThisSensorInputs[j] > maxLightSensorEval )
					{	
						/* Store maximum value */
						maxLightSensorEval = pfThisSensorInputs[j];
					}
					if (j==0)
						lightS0 = pfThisSensorInputs[j];
					else if (j==2)
						lightS2 = pfThisSensorInputs[j];
					else if (j==5)
						lightS5 = pfThisSensorInputs[j];
					else if (j==7)
						lightS7 = pfThisSensorInputs[j];
				}
				break;
			case SENSOR_REAL_BLUE_LIGHT:
				unThisSensorsNumberOfInputs = (*i)->GetNumberOfInputs();
				pfThisSensorInputs = (*i)->GetComputedSensorReadings();

				for (int j = 0; j < unThisSensorsNumberOfInputs; j++)
				{
					if ( pfThisSensorInputs[j] > maxBlueLightSensorEval )
					{	
						maxBlueLightSensorEval = pfThisSensorInputs[j];
					}
					if (j==0)
						blueLightS0 = pfThisSensorInputs[j];
					else if (j==2)
						blueLightS2 = pfThisSensorInputs[j];
					else if (j==5)
						blueLightS5 = pfThisSensorInputs[j];
					else if (j==7)
						blueLightS7 = pfThisSensorInputs[j];
				}
				break;
			
			case SENSOR_REAL_RED_LIGHT:
				unThisSensorsNumberOfInputs = (*i)->GetNumberOfInputs();
				pfThisSensorInputs = (*i)->GetComputedSensorReadings();

				for (int j = 0; j < unThisSensorsNumberOfInputs; j++)
				{
					if ( pfThisSensorInputs[j] > maxRedLightSensorEval )
					{	
						maxRedLightSensorEval = pfThisSensorInputs[j];
					}
					if (j==0)
						redLightS0 = pfThisSensorInputs[j];
					else if (j==2)
						redLightS2 = pfThisSensorInputs[j];
					else if (j==5)
						redLightS5 = pfThisSensorInputs[j];
					else if (j==7)
						redLightS7 = pfThisSensorInputs[j];
				}
				break;

			/* If sensor is BATTERY */
			case SENSOR_RED_BATTERY:
				redBattery = (*i)->GetComputedSensorReadings();
				break;
			
			/* If sensor is CONTACT */
			case SENSOR_CONTACT:
				/* Get number of inputs */
				unThisSensorsNumberOfInputs = (*i)->GetNumberOfInputs();
				/* Get actual values */
				pfThisSensorInputs = (*i)->GetComputedSensorReadings();

				/* For every input */
				for (int j = 0; j < unThisSensorsNumberOfInputs; j++)
				{
					/* If reading bigger than maximum */
					if ( pfThisSensorInputs[j] > maxContactSensorEval )
					{
						/* Store maximum value */
						maxContactSensorEval = pfThisSensorInputs[j];
					}
				}
				break;
		}
	}
	
	/* FROM HERE YOU NEED TO CREATE YOU FITNESS */	

	double fitness = 1.0;

	if(redBattery[0] > 0.35){
		if (groundMemory[0] > 0.0){
 		  fitness *= ( lightS0 + lightS2 + lightS5 + lightS7)/1.5;
  		  if (m_unGreyFlag == 0){
  		    m_unGreyFlag = 1;
  		    m_unGreyCounter++;
  		  }
 		}else{
 		   fitness *= ( blueLightS0 + blueLightS2 + blueLightS5 + blueLightS7);
 		   if (m_unGreyFlag == 1){ m_unGreyFlag = 0;}
  	        }
	}else{
		fitness *= ( redLightS0 + redLightS2+ redLightS5 + redLightS7)*2;
	}
	

  	fitness *= (1 - maxProxSensorEval) * maxSpeedEval * (leftSpeed * rightSpeed) * sameDirectionEval* (fmin(redBattery[0],0.2)/0.2);//maxRedLightSensorEval; 
	
	/* TO HERE YOU NEED TO CREATE YOU FITNESS */	

	m_unNumberOfSteps++;
	m_fComputedFitness += fitness;

		/* Get Collisions */
	int nContact = 0;
	CContactSensor *m_seContact = (CContactSensor*) m_pcEpuck->GetSensor(SENSOR_CONTACT);
	double* contact = m_seContact->GetSensorReading(m_pcEpuck);
	for ( int j = 0 ; j < m_seContact->GetNumberOfInputs() ; j++)
	{
		if(contact[j] > 0.0) 
			nContact=1;
	} 

	if ( nContact == 1 )
		m_unCollisionsNumber++;		
}

/******************************************************************************/
/******************************************************************************/
