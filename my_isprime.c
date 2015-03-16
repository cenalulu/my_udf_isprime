#include <my_global.h>
#include <mysql.h>
#include <string.h>


#ifdef HAVE_DLOPEN


C_MODE_START;
my_bool isprime_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
void isprime_deinit(UDF_INIT *initid);
long long  isprime(UDF_INIT *initid, UDF_ARGS *args,
	        char *is_null, char *error);
C_MODE_END;



my_bool isprime_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  initid->ptr = (char*)malloc(sizeof(int));
  *(initid->ptr) = 0;
  if (args->arg_count != 1)
  {
    strcpy(message,"Incorrect parameter count in the call to UDF function 'isprime'");
    return 1;
  }
  if (args->arg_type[0] != INT_RESULT){
      *(initid->ptr) = 1;
  }
  return 0;
}

void isprime_deinit(UDF_INIT *initid __attribute__((unused)))
{
    free(initid->ptr);
}

long long isprime(UDF_INIT *initid ,UDF_ARGS *args,
               /* UDF_ARGS *args, char *result, unsigned long *length, */
               char *is_null, char *error )
{

    const long long input =*((long long *) args->args[0]);
    if( *( (int*)(initid->ptr) ) == 1){
        return 0;
    }else{
        if(input>0){
            if(input % 2 ==0){
                if( input != 2 ){
                    return 0;
                }else{
                    return 1;
                }
            }else{
                for(long long i=3;i<input;i=i+2){
                    if( input % i == 0 ){
                        return 0;
                    }
                }
            }
            return 1;
        }
        else{
            return 0;
        }
    }

}

#endif
