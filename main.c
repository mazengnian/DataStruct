int main(int argc, const char *argv[]){
    hash_t *hs;
    int i, key;
    int data[] = {23,15,26,15,36,64,12,78};
    linklist_t  r;
    hs = hash_creat();
    if(hs == NULL){
        return -1;
    }
    for(i = 0; i < sizeof(data) / sizeof(int); i++){
        hash_insert(hs, data[i]);
    }
    printf("input:");
    scanf("%d", &key);
    r = hash_search(hs, key);
    if(r == NULL){
        printf("not found\n");
    }else{
        printf("found:%d %d", key, r->key);
    }
    return 0;
}
