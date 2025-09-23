https://leetcode.com/problems/design-movie-rental-system/description/?envType=daily-question&envId=2025-09-21

class MovieRentingSystem {
public:
    class movies{
        public : 
        int shop;
        int price;
        movies(int s, int p){
            shop = s;
            price = p;
        }
    };
    class rentmovie{
        public : 
        int shop;
        int movie;
        int price;
        rentmovie(int s, int m, int p){
           shop = s;
           movie = m;
           price = p;
        }
    };
    class comparator{
        public: 
        bool operator()(const movies &m1, const movies &m2)const{
            if(m1.price==m2.price) return m1.shop<m2.shop;
            return m1.price<m2.price;
        }
    };
    class comparator2{
        public: 
        bool operator()(const rentmovie &r1, const rentmovie &r2)const{
            if(r1.price==r2.price){
               if(r1.shop==r2.shop) return r1.movie<r2.movie;
               return r1.shop<r2.shop;
            } 
            return r1.price<r2.price;
        }
    };
    unordered_map<int,set<movies,comparator>>movietoshop; // available movies
    set<rentmovie,comparator2>rentmoviecontainer;
    unordered_map<string,int>shopmovietoprice; //{shop,movie} -> price
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto v:entries){
            int shop = v[0];
            int movie = v[1];
            int price = v[2];
            movietoshop[movie].insert(movies(shop,price));
            string key = to_string(shop) + "$" + to_string(movie);
            shopmovietoprice[key] = price;
        }

    }
    
    vector<int> search(int movie) {
        // available movies
        vector<int>ans;
        int cnt=5;
        for(auto it = movietoshop[movie].begin();it!=movietoshop[movie].end() && cnt--;it++){
            int shop = it->shop;
            int price = it->price;
            ans.push_back(shop);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        string key = to_string(shop) + "$" + to_string(movie);
        int price = shopmovietoprice[key];
        movietoshop[movie].erase(movies(shop,price));
        if(movietoshop[movie].empty()) movietoshop.erase(movie);
        rentmoviecontainer.insert(rentmovie(shop,movie,price));
    }
    
    void drop(int shop, int movie) {
        string key = to_string(shop) + "$" + to_string(movie);
        int price = shopmovietoprice[key];
        rentmoviecontainer.erase(rentmovie(shop,movie,price));
        movietoshop[movie].insert(movies(shop,price));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int cnt=5;
        for(auto it = rentmoviecontainer.begin();it!=rentmoviecontainer.end() && cnt--;it++){
            int movie = it->movie;
            int shop = it->shop;
            int price = it->price;
            ans.push_back({shop,movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */